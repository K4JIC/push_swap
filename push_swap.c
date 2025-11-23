/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:38:11 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/23 19:29:26 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include "utils.h"

int	handle_single_input(t_lst *stack, char *argv)
{
	char	**sp;
	int		words;
	int		i;

	sp = ft_split(argv);
	words = count_words(argv);
	i = 0;
	while (i < words)
	{
		lst_add_back(stack, ft_atoi(sp[i]));
		i++;
	}
	return (0);
}

int	handle_multiple_input(t_lst *stack, int argc, char **argv)
{
	int	i;
	int	res;

	i = 0;
	while (i < argc)
	{
		res = lst_add_back(stack, ft_atoi(argv[i]));
		if (res == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	int		res;

	stack_a = lst_new(0, 1);
	if (argc == 2)
		res = handle_single_input(stack_a, argv[1]);
	if (argc >= 3)
		res = handle_multiple_input(stack_a, argc, argv);
	if (res == -1)
		return (1);
}

