/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:38:11 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/27 21:18:59 by tozaki           ###   ########.fr       */
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

	if (!is_valid_use_of_space(argv))
		return (FAIL);
	sp = ft_split(argv);
	n = count_words(argv);
	i = 0;
	while (i < n)
	{
		if (validate_atoi(sp[i], &num) == FAIL)
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

int	error_msg(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	do_sort(t_node *stack_a, t_node *stack_b)
{
	int	res;

	if (issorted(stack_a))
		return (SUCCESS);
	if (nodelen(stack_a) == 2)
		res = sort_len2(stack_a, stack_b);
	else if (nodelen(stack_a) == 3)
		res = sort_len3(stack_a, stack_b);
	else if (nodelen(stack_a) <= 6)
		res = sort_len6(stack_a, stack_b);
	else
		res = radix_sort(stack_a, stack_b);
	if (res == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*cur;
	int		res;

	res = SUCCESS;
	stack_a = init_node();
	if (!stack_a)
		return (1);
	stack_b = init_node();
	if (!stack_b)
		return (free_node(stack_a), 1);
	if (argc == 2)
		res = handle_single_input(stack_a, argv[1]);
	else if (argc >= 3)
		res = handle_multiple_input(stack_a, argc, argv);
	if (res == FAIL)
		return (free_node(stack_a), free_node(stack_b), error_msg());
	if (check_duplicate(stack_a) == FAIL)
		return (free_node(stack_a), free_node(stack_b), error_msg());
	if (set_index(stack_a) == FAIL)
		return (free_node(stack_a), free_node(stack_b), 1);
	if (do_sort(stack_a, stack_b) == FAIL)
		return (free_node(stack_a), free_node(stack_b), 1);
	return (free_node(stack_a), free_node(stack_b), 0);
}

// #include <stdio.h>

// void	print_stack(t_node *dummy, char c)
// {
// 	t_node	*cur;

// 	cur = dummy->next;
// 	while (cur->valid)
// 	{
// 		printf("%c : %i\n", c, (int)(cur->num ^ (1u << 31)));
// 		// printf("%c : %u\n", c, cur->num);
// 		cur = cur->next;
// 	}
// }

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;
// 	t_node	*cur;
// 	int		res;
// void	print_stack(t_node *dummy, char c)
// {
// 	t_node	*cur;

// 	cur = dummy->next;
// 	while (cur->valid)
// 	{
// 		printf("%c : %i\n", c, (int)(cur->num ^ (1u << 31)));
// 		// printf("%c : %u\n", c, cur->num);
// 		cur = cur->next;
// 	}
// }
// int	main(int argc, char **argv)
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;
// 	t_node	*cur;
// 	int		res;

// 	stack_a = init_node();
// 	if (!stack_a)
// 		return (1);
// 	stack_b = init_node();
// 	if (!stack_b)
// 		return (1);
// 	if (argc == 2)
// 		res = handle_single_input(stack_a, argv[1]);
// 	else if (argc >= 3)
// 		res = handle_multiple_input(stack_a, argc, argv);
// 	if (res == FAIL)
// 		return (error_msg());
// 	if (check_duplicate(stack_a) == FAIL)
// 		return (error_msg());
// 	if (assign_index(stack_a) == FAIL)
// 		return (1);
// 	do_sort(stack_a, stack_b);
// 	print_stack(stack_a, 'a'); print_stack(stack_b, 'b');
// 	free_node(stack_a);
// 	free_node(stack_b);
// 	return (0);
// }