/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:38:11 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/24 14:45:06 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "utils.h"

int	handle_single_input(t_node *stack, char *argv)
{
	char	**sp;
	t_node	*res;
	int		n;
	int		i;

	sp = ft_split(argv);
	n = count_words(argv);
	i = 0;
	while (i < n)
	{
		res = node_add_back(stack, node_new(ft_atoi(sp[i])));
		if (!res)
		{
			free_sp(sp);
			return (-1);
		}
		i++;
	}
	free_sp(sp);
	return (0);
}

int	handle_multiple_input(t_node *stack, int argc, char **argv)
{
	t_node	*res;
	int		i;

	i = 1;
	while (i < argc)
	{
		res = node_add_back(stack, node_new(ft_atoi(argv[i])));
		if (!res)
			return (-1);
		i++;
	}
	return (0);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*cur;
	int		res;

	stack_a = init_node();
	if (!stack_a)
		return (1);
	if (argc == 2)
		res = handle_single_input(stack_a, argv[1]);
	else if (argc >= 3)
		res = handle_multiple_input(stack_a, argc, argv);
	if (res == -1)
		return (1);
	cur = stack_a->next;
	while (cur->valid)
	{
		printf("%d\n", cur->num);
		cur = cur->next;
	}
	free_node(stack_a);
	return (0);
}

