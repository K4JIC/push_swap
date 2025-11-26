/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:58:04 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/26 15:47:07 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "define.h"

int	ss(t_node *stack_a, t_node *stack_b)
{
	int	res;

	res = sa(stack_a, stack_b);
	if (!res)
		return (FAIL);
	res = sb(stack_a, stack_b);
	if (!res)
		return (FAIL);
	write(1, "ss\n", 3);
	return (SUCCESS);
}

int	rr(t_node *stack_a, t_node *stack_b)
{
	int	res;

	res = ra(stack_a, stack_b);
	if (!res)
		return (FAIL);
	res = rb(stack_a, stack_b);
	if (!res)
		return (FAIL);
	write(1, "rr\n", 3);
	return (SUCCESS);
}

int	rrr(t_node *stack_a, t_node *stack_b)
{
	int	res;

	res = rra(stack_a, stack_b);
	if (!res)
		return (FAIL);
	res = rrb(stack_a, stack_b);
	if (!res)
		return (FAIL);
	write(1, "rrr\n", 4);
	return (SUCCESS);
}
