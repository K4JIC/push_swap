/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_len3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:34:39 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/25 16:32:22 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "sort.h"
#include "define.h"

int	match_pattern_len3(t_node *stack_a, t_node *stack_b, t_numbers n)
{
	int	res;

	if (n.fir < n.sec && n.sec < n.thir && n.thir > n.fir)
	{
		res = rra(stack_a, stack_b);
		res = sa(stack_a, stack_b);
	}
	else if (n.fir > n.sec && n.sec < n.thir && n.thir > n.fir)
		res = sa(stack_a, stack_a);
	else if (n.fir < n.sec && n.sec > n.thir && n.thir < n.fir)
		res = rra(stack_a, stack_b);
	else if (n.fir > n.sec && n.sec < n.thir && n.thir < n.fir)
		res = ra(stack_a, stack_b);
	else if (n.fir > n.sec && n.sec > n.thir && n.thir < n.fir)
	{
		res = sa(stack_a, stack_b);
		res = rra(stack_a, stack_b);
	}
	else
		return (FAIL);
	if (res == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	sort_len3(t_node *stack_a, t_node *stack_b)
{
	t_numbers	numbers;

	if (!stack_a || !stack_b)
		return (FAIL);
	if (issorted(stack_a))
		return (SUCCESS);
	numbers.fir = stack_a->next->num;
	numbers.sec = stack_a->next->next->num;
	numbers.thir = stack_a->next->next->num;
	if (match_pattern_len3(stack_a, stack_b, numbers) == FAIL)
		return (FAIL);
	return (SUCCESS);
}