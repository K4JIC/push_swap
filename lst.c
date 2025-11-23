/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:48:55 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/23 21:36:56 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lst.h"

t_lst	*lst_new(int num, int index)
{
	t_lst	*new;

	new = (t_lst*)malloc(sizeof(t_lst) * 1);
	if (!new)
		return (NULL);
	new->num = num;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_lst	*lst_last(t_lst *root)
{
	t_lst	*cur;

	cur = root;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

t_lst	*lst_add_back(t_lst *root, t_lst *new)
{
	t_lst	*last;

	last = lst_last(root);
	last->next = new;
	new->prev = last;
	return (root);
}
