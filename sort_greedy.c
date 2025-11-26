/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:19:50 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/26 15:59:38 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "define.h"

int	assign_index(t_node *stack_a)
{
	unsigned int		len;
	t_node				*max;
	t_node				*cur;
	unsigned int		index;

	if (!stack_a)
		return (FAIL);
	len = (unsigned int)nodelen(stack_a);
	index = 1;
	while (index < len)
	{
		max = NULL;
		cur = stack_a->next;
		while (cur->valid)
		{
			if ((!max || max->num < cur->num) && !cur->index)
				max = cur;
			cur = cur->next;
		}
		max->index = len - index;
		index++;
	}
	return (SUCCESS);
}
