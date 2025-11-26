/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_len6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:02:57 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/26 20:00:26 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "define.h"
#include "sort.h"

static t_node	*search_min(t_node *stack_a)
{
	t_node	*cur;
	t_node	*min;

	if (!stack_a)
		return (NULL);
	cur = stack_a->next;
	min = cur;
	while (cur->valid)
	{
		if (min->index > cur->index)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

static int	assign_rules(t_node *stack_a, t_node *stack_b, t_node *min)
{
	int		len;
	t_node	*cur;
	int		depth;

	len = nodelen(stack_a);
	cur = stack_a->next;
	depth = 0;
	while (cur != min && cur->valid)
	{
		depth++;
		cur = cur->next;
	}
	if (len - depth < depth - 0)
		rra(stack_a, stack_b);
	else
		ra(stack_a, stack_b);
	return (SUCCESS);
}

int	sort_len6(t_node *stack_a, t_node *stack_b)
{
	t_node	*cur;
	t_node	*min;

	if (!stack_a || !stack_b)
		return (FAIL);
	cur = stack_a->next;
	while (nodelen(stack_a) > 3)
	{
		min = search_min(stack_a);
		while (cur != min)
		{
			assign_rules(stack_a, stack_b, min);
			cur = stack_a->next;
		}
		pb(stack_a, stack_b);
	}
	if (sort_len3(stack_a, stack_b) == FAIL)
		return (FAIL);
	while (nodelen(stack_b))
		pa(stack_a, stack_b);
	if (!issorted(stack_a))
		return (FAIL);
	return (SUCCESS);
}
