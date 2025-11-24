/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:50:46 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/24 20:33:08 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "define.h"

int	sa(t_node *stack_a, t_node *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stack_a || !stack_b)
		return (FAIL);
	if (nodelen(stack_a) <= 1)
		return (FAIL);
	first = stack_a->next;
	second = first->next;
	third = second->next;
	stack_a->next = second;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = stack_a;
	third->prev = first;
	write(1, "sa\n", 3);
	return (SUCCESS);
}

int	sb(t_node *stack_a, t_node *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stack_a || !stack_b)
		return (FAIL);
	if (nodelen(stack_b) <= 1)
		return (FAIL);
	first = stack_b->next;
	second = first->next;
	third = second->next;
	stack_b->next = second;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = stack_b;
	write(1, "sb\n", 3);
	return (SUCCESS);
}

int	pa(t_node *stack_a, t_node *stack_b)
{
	t_node	*res;
	
	res = node_add_front(stack_a, node_pop(&stack_b));
	if (!res)
		return (FAIL);
	write(1, "pa\n", 3);
	return (SUCCESS);
}

int	pb(t_node *stack_a, t_node *stack_b)
{
	t_node	*res;

	res = node_add_front(stack_b, node_pop(&stack_a));
	if (!res)
		return (FAIL);
	write(1, "pb\n", 3);
	return (SUCCESS);
}
