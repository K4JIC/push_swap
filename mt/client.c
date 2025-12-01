/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:54:07 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/01 18:01:08 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "client.h"
#include "ft_printf/libft/libft.h"

volatile int	g_server_state; 

void	ack_handler(int signo)
{
	if (signo == SIGUSR2)
		g_server_state = BUSY;
	else if (signo == SIGUSR1)
		g_server_state = IDLING;
}

void	handshake_with_server(int s_pid)
{
	kill(s_pid, SIGUSR1);
	sleep(10);
}

void	send_char(int s_pid, char c)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		g_server_state = BUSY;
		bit = ((c >> i) & 1);
		if (bit)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		while (g_server_state == BUSY)
			usleep(1);
		i++;
	}
}

void	send_string(int s_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(s_pid, str[i]);
		i++;
	}
	send_char(s_pid, '\0');
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
		handshake_with_server(s_pid);
	send_string(s_pid, argv[2]);
	return (0);
}
