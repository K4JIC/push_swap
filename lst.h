/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:40:40 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/23 19:26:58 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_lst{
	int				num;
	int				index;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

t_lst	*lst_new(int num, int top);
t_lst	*lst_last(t_lst *root);
t_lst	*lst_add_back(t_lst *root, int num);

#endif
