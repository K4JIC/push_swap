/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:00:33 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/24 14:42:09 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include <stdlib.h>

t_node	*node_pop(t_node **dummy)
{
	t_node	*top;

	if (!dummy || !*dummy || (*dummy)->next == *dummy)
		return (NULL);
	top = (*dummy)->next;
	(*dummy)->next = top->next;
	top->next->prev = (*dummy);
	return (top);
}

void	free_node(t_node *dummy)
{
	t_node	*cur_node;
	t_node	*prev_node;

	cur_node = dummy->next;
	while (cur_node->valid)
	{
		prev_node = cur_node;
		cur_node = cur_node->next;
		free(prev_node);
	}
	free(cur_node);
}