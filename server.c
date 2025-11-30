/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:54:12 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/30 22:16:24 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "server.h"
#include "ft_printf/ft_printf.h"

void	sig_handler(int signo, siginfo_t *info, void *context)
{
	static char		c = '\0';
	static int		cnt = 0;
	static pid_t	client_pid = 0;

	if (client_pid != 0 && client_pid != info->si_pid)
		return ((void)kill(info->si_pid, SIGUSR2));
	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	c |= ((signo == SIGUSR1) << cnt);
	cnt++;
	if (cnt == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		kill(client_pid, SIGUSR1);
		c = '\0';
		cnt = 0;
		if (c == '\0')
			client_pid = 0;
	}
	else
		kill(client_pid, SIGUSR1);
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
	if (sigaction(SIGUSR1, &act, NULL) != 0)
		return (1);
	if (sigaction(SIGUSR2, &act, NULL) != 0)
		return (1);
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}
