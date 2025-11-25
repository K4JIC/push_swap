/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:48:55 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/24 12:51:49 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "node.h"
#include "utils.h"

t_node	*init_node()
{
	t_node	*dummy;

	dummy = (t_node *)malloc(sizeof(t_node) * 1);
	if (!dummy)
		return (NULL);
	dummy->num = 0;
	dummy->valid = false;
	dummy->next = dummy;
	dummy->prev = dummy;
	return (dummy);
}

t_node	*node_new(int num)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node) * 1);
	if (!new)
		return (NULL);
	new->num = (unsigned int)(num ^ (1u << 31));
	new->valid = true;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node	*node_last(t_node *root)
{
	t_node	*cur;

	if (!root)
		return (NULL);
	cur = root;
	while (cur->next->valid)
		cur = cur->next;
	return (cur);
}

t_node	*node_add_back(t_node *dummy, t_node *new)
{
	t_node	*last;

	if (!dummy || !new)
		return (NULL);
	last = node_last(dummy);
	last->next = new;
	new->prev = last;
	new->next = dummy;
	dummy->prev = new;
	if (dummy->next == dummy)
		dummy->next = new;
	return (dummy);
}

t_node	*node_add_front(t_node *dummy, t_node *new)
{
	t_node	*tmp;

	if (!dummy || !new)
		return (NULL);
	tmp = dummy->next;
	new->prev = dummy;
	new->next = tmp;
	dummy->next = new;
	if (dummy->prev == dummy)
		dummy->prev = new;
	return (dummy);
}
