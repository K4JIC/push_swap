/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:38:11 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/25 22:07:25 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "define.h"
#include "input.h"
#include "utils.h"
#include "sort.h"

int	handle_single_input(t_node *stack, char *argv)
{
	char	**sp;
	t_node	*res;
	int		n;
	int		i;
	int		num;

	sp = ft_split(argv);
	n = count_words(argv);
	i = 0;
	while (i < n)
	{
		if (!validate_atoi(sp[i], &num) == FAIL)
			return (FAIL);
		res = node_add_back(stack, node_new(num));
		if (!res)
		{
			free_sp(sp);
			return (FAIL);
		}
		i++;
	}
	free_sp(sp);
	return (SUCCESS);
}

int	handle_multiple_input(t_node *stack, int argc, char **argv)
{
	t_node	*res;
	int		i;
	int		num;

	i = 1;
	while (i < argc)
	{
		if (validate_atoi(argv[i], &num) == FAIL)
			return (FAIL);
		res = node_add_back(stack, node_new(num));
		if (!res)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	error_msg()
{
	write(1, "Error\n", 6);
	return (1);
}

#include <stdio.h>

void	print_stack(t_node *dummy, char c)
{
	t_node	*cur;

	cur = dummy->next;
	while (cur->valid)
	{
		printf("%c : %i\n", c, (int)(cur->num ^ (1u << 31)));
		// printf("%c : %u\n", c, cur->num);
		cur = cur->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*cur;
	int		res;

	stack_a = init_node();
	if (!stack_a)
		return (1);
	stack_b = init_node();
	if (!stack_b)
		return (1);
	if (argc == 2)
		res = handle_single_input(stack_a, argv[1]);
	else if (argc >= 3)
		res = handle_multiple_input(stack_a, argc, argv);
	if (res == FAIL)
		return (error_msg());
	if (check_duplicate(stack_a) == FAIL)
		return (error_msg());
	radix_sort(stack_a, stack_b);
	print_stack(stack_a, 'a'); print_stack(stack_b, 'b');
	free_node(stack_a);
	free_node(stack_b);
	return (0);
}
