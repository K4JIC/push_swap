/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:54:12 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/01 18:17:31 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "server.h"
#include "ft_printf/ft_printf.h"

void	handshake_with_client(volatile sig_atomic_t *talking_pid, pid_t received_pid)
{
	if (*talking_pid == 0)
	{
		*talking_pid = received_pid;
		kill(received_pid, SIGUSR1);
	}
	else
		kill(received_pid, SIGUSR2);
}

void	sig_handler(int signo, siginfo_t *info, void *context)
{
	static volatile sig_atomic_t	talking_pid = 0;
	static volatile sig_atomic_t	c = '\0';
	static volatile sig_atomic_t	cnt = 0;

	(void)context;
	if (talking_pid != info->si_pid)
		return (handshake_with_client(&talking_pid, info->si_pid));
	c |= ((signo == SIGUSR1) << cnt);
	cnt++;
	if (cnt == 8)
	{
		if (c == '\0')
		{
			talking_pid = 0;
			write(1, "\n", 1);
		}
		else
			write(1, &c, 1);
		c = '\0';
		cnt = 0;
	}
	kill(info->si_pid, SIGUSR1);
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
