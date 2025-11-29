/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:32:55 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/29 17:09:08 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

typedef struct s_server
{
	sig_atomic_t	bit;
	sig_atomic_t	cnt;
	sig_atomic_t	client_pid;
	sig_atomic_t	c;
}			t_server;

#endif
