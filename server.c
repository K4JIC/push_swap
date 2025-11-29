/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:54:12 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/29 17:54:54 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"
#include "server.h"

t_server	g_server;

void	sig_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	g_server.client_pid = info->si_pid;
	if (signo == SIGUSR1)
		g_server.bit = 1;
	else if (signo == SIGUSR2)
		g_server.bit = 0;
	g_server.sig_received = 1;
}

void	display_char(void)
{
	while (!g_server.sig_received)
		pause();
	g_server.sig_received = 0;
	g_server.c |= (g_server.bit << g_server.cnt);
	g_server.cnt++;
	if (g_server.cnt == 8)
	{
		if (g_server.c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", g_server.c);
		g_server.c = 0;
		g_server.cnt = 0;
	}
	kill(g_server.client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;
	int					pid;

	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	g_server.cnt = 0;
	g_server.c = 0;
	g_server.bit = 0;
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
		display_char();
	return (0);
}
