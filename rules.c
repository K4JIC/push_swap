/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:50:46 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/24 14:57:01 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "define.h"

int	pa(t_node *stack_a, t_node *stack_b)
{
	t_node	*res;
	
	res = node_add_front(stack_a, node_pop(&stack_b));
	if (!res)
		return (FAIL);
	return (SUCCESS);
}

int	pb(t_node *stack_a, t_node *stack_b)
{
	t_node	*res;

	res = node_add_front(stack_b, node_pop(&stack_a));
	if (!res)
		return (FAIL);
	return (SUCCESS);
}

