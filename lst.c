/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:48:55 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/23 19:27:30 by tozaki           ###   ########.fr       */
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
	return (new);
}

t_lst	*lst_last(t_lst *root)
{
	t_lst	*cur;

	cur = root;
	while (cur)
		cur = cur->next;
	return (cur);
}

t_lst	*lst_add_back(t_lst *root, int num)
{
	t_lst	*new;
	t_lst	*last;

	last = lst_last(root);
	new = lst_new(num, 0);
	last->next = new;
	new->prev = last;
	return (root);
}
