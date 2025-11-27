/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalaction_training.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:14:49 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/27 20:43:07 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// #define __USE_POSIX

int	status;

void	handler(int sig)
{
	status = 1;
	printf("status = %d\n", status);
}

int	main(void)
{
	struct sigaction	act;
	
	act.sa_handler = handler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGINT);
	sigaction(SIGUSR1, &act, NULL);
	while (1)
	{
		sleep(1);
		printf(".");
	}
}
