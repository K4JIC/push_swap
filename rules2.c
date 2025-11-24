/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:22:43 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/24 20:33:40 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "define.h"

int	ra(t_node *stack_a, t_node *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!stack_a || !stack_b)
		return (FAIL);
	if (nodelen(stack_a) <= 1)
		return (FAIL);
	first = stack_a->next;
	second = first->next;
	last = node_last(stack_a);
	last->next = first;
	stack_a->next = second;
	stack_a->prev = first;
	first->next = stack_a;
	first->prev = last;
	second->prev = stack_a;
	write(1, "ra\n", 3);
	return (SUCCESS);
}

int	rb(t_node *stack_a, t_node *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!stack_a || !stack_b)
		return (FAIL);
	if (nodelen(stack_b) <= 1)
		return (FAIL);
	first = stack_b->next;
	second = first->next;
	last = node_last(stack_b);
	last->next = first;
	stack_b->next = second;
	stack_b->prev = first;
	first->next = stack_b;
	first->prev = last;
	second->prev = stack_b;
	write(1, "rb\n", 3);
	return (SUCCESS);
}

int	rra(t_node *stack_a, t_node *stack_b)
{
	t_node	*first;
	t_node	*last;
	t_node	*llast;

	if (!stack_a || !stack_b)
		return (FAIL);
	if (nodelen(stack_a) <= 1)
		return (FAIL);
	first = stack_a->next;
	last = node_last(stack_a);
	llast = last->prev;
	llast->next = stack_a;
	last->next = first;
	last->prev = stack_a;
	stack_a->next = last;
	stack_a->prev = llast;
	first->prev = last;
	write(1, "rra\n", 4);
	return (SUCCESS);
}

int	rrb(t_node *stack_a, t_node *stack_b)
{
	t_node	*first;
	t_node	*last;
	t_node	*llast;

	if (!stack_a || !stack_b)
		return (FAIL);
	if (nodelen(stack_b) <= 1)
		return (FAIL);
	first = stack_b->next;
	last = node_last(stack_b);
	llast = last->prev;
	llast->next = stack_b;
	last->next = first;
	last->prev = stack_b;
	stack_b->next = last;
	stack_b->prev = llast;
	first->prev = last;
	write(1, "rrb\n", 4);
	return (SUCCESS);
}
