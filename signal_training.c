/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_training.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:41:09 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/26 22:06:12 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void	sig_usr(int signo)
{
	if (signo == SIGUSR1)
		printf("usr1\n");
	else if (signo == SIGUSR2)
		printf("usr2\n");
	else
		printf("unknown signal\n");
}

int	main(void)
{
	if (sigaction(SIGUSR1, sig_usr) == SIG_ERR)
		printf("error\n");
	if (sigaction(SIGUSR2, sig_usr) == SIG_ERR)
		printf("error\n");
	while (1)
		pause();
}