/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:23:31 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/26 15:50:13 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "define.h"

int	issorted(t_node *dummy)
{
	t_node	*cur;

	cur = dummy->next;
	while (cur->next->valid)
	{
		if (cur->index > cur->next->index)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static int	radix_sort_one_digit(t_node *stack_a, t_node *stack_b, int digit)
{
	int		alen;
	int		blen;
	int		i;
	int		j;

	if (!stack_a, !stack_b)
		return (FAIL);
	alen = nodelen(stack_a);
	i = 0;
	while (i < alen)
	{
		if (!(stack_a->next->index & (1u << digit)))
			pb(stack_a, stack_b);
		else
			ra(stack_a, stack_b);
		i++;
	}
	blen = nodelen(stack_b);
	j = 0;
	while (j < blen)
	{
		pa(stack_a, stack_b);
		j++;
	}
	return (SUCCESS);
}

int	radix_sort(t_node *stack_a, t_node *stack_b)
{
	int	digit;

	digit = 0;
	while (!issorted(stack_a))
	{
		if (radix_sort_one_digit(stack_a, stack_b, digit) == FAIL)
			return (FAIL);
		digit++;
	}
	return (SUCCESS);
}
