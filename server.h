/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:32:55 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/29 17:41:50 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>

typedef struct s_server
{
	volatile sig_atomic_t	sig_received;
	volatile sig_atomic_t	client_pid;
	volatile sig_atomic_t	bit;
	char					c;
	int						cnt;
}			t_server;

#endif
