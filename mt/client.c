/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:54:07 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/01 22:18:29 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "client.h"
#include "libft.h"

volatile sig_atomic_t	g_server_state;

void	ack_handler(int signo)
{
	if (signo == SIGUSR2)
		g_server_state = BUSY;
	else if (signo == SIGUSR1)
		g_server_state = IDLING;
}

int	handshake_with_server(int s_pid)
{
	int	wait_time;

	if (kill(s_pid, SIGUSR1) != SUCCESS)
		return (FAIL);
	wait_time = 0;
	while (g_server_state == BUSY && wait_time < 5)
	{
		sleep(1);
		wait_time++;
	}
	if (g_server_state == BUSY)
		return (TIMEOUT);
	return (SUCCESS);
}

int	send_char(int s_pid, char c)
{
	int	i;
	int	bit;
	int	wait_time;

	i = 0;
	while (i < 8)
	{
		g_server_state = BUSY;
		bit = ((c >> i) & 1);
		if (bit)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		wait_time = 1;
		while (g_server_state == BUSY && i < 100000)
		{
			usleep(wait_time);
			wait_time *= 2;
		}
		if (g_server_state == BUSY)
			return (TIMEOUT);
		i++;
	}
	return (SUCCESS);
}

int	send_string(int s_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (send_char(s_pid, str[i]) == TIMEOUT)
			return (TIMEOUT);
		i++;
	}
	if (send_char(s_pid, '\0') == TIMEOUT)
		return (TIMEOUT);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	int					s_pid;

	if (argc != 3)
		return (1);
	act.sa_handler = ack_handler;
	act.sa_flags = SA_RESTART;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) != 0)
		return (1);
	if (sigaction(SIGUSR2, &act, NULL) != 0)
		return (1);
	s_pid = ft_atoi(argv[1]);
	if (s_pid <= PID_MIN || PID_MAX < s_pid)
		return (1);
	g_server_state = BUSY;
	while (g_server_state == BUSY)
	{
		if (handshake_with_server(s_pid) < 0)
			return (1);
	}
	if (send_string(s_pid, argv[2]) == TIMEOUT)
		return (1);
	return (0);
}
