/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:54:07 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/27 21:53:57 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	cnt;

void	send_char(int s_pid)
{
	int	bit;

	bit = (**c & 1u << cnt);
	if (bit == 1)
		kill(s_pid, SIGUSR1);
	if (bit == 0)
		kill(s_pid, SIGUSR2);
	cnt++;
	if (cnt == 8)
	{
		cnt = 0;
		*c++;
	}
}

/**
 * struct sigaction {
 * 		void     (*sa_handler)(int);
 * 		void     (*sa_sigaction)(int, siginfo_t *, void *);
 * 		sigset_t   sa_mask;
 * 		int        sa_flags;
 * 		void     (*sa_restorer)(void);
 * };
 */

int	main(int argc, char **argv)
{
	struct sigaction	act;

	if (argc == 2 || argc >= 4)
		return (1);
	act.sa_handler = send_char;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	while (1)
		pause();
	return (0);
}