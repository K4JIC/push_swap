/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:54:07 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/29 18:01:00 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "ft_printf/libft/libft.h"
#include <stdlib.h>

volatile sig_atomic_t	g_ack_received;

void	ack_handler(int signo)
{
	(void)signo;
	g_ack_received = 1;
}

void	send_bit(int s_pid, int bit)
{
	if (bit)
		kill(s_pid, SIGUSR1);
	else
		kill(s_pid, SIGUSR2);
}

void	send_char(int s_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack_received = 0;
		send_bit(s_pid, (c >> i) & 1);
		while (!g_ack_received)
			pause();
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

	if (argc != 3)
		return (1);
	act.sa_handler = ack_handler;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	g_ack_received = 0;
	send_string(ft_atoi(argv[1]), argv[2]);
	return (0);
}
