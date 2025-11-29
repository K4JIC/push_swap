/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:36:51 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/29 13:20:37 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "define.h"
#include "utils.h"

int	is_valid_use_of_space(char *str)
{
	int	i;
	int	in_word;

	i = 0;
	if (str[i] == ' ')
		return (0);
	in_word = 1;
	while (str[i])
	{
		if (!in_word)
		{
			if (str[i] == ' ')
				return (0);
		}
		in_word = 1;
		if (str[i] == ' ')
			in_word = 0;
		i++;
	}
	if (!in_word)
		return (0);
	return (1);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i >= DIGIT_MAX + 2)
		return (0);
	return (1);
}

int	validate_atoi(char *str, int *n)
{
	long	ln;

	if (!is_valid_len(str))
		return (FAIL);
	if (!is_valid_number(str))
		return (FAIL);
	ln = ft_atol(str);
	if (ln > INT_MAX || ln < INT_MIN)
		return (FAIL);
	*n = ft_atoi(str);
	return (SUCCESS);
}

int	check_duplicate(t_node *stack_a)
{
	t_node	*cur1;
	t_node	*cur2;

	cur1 = stack_a->next;
	while (cur1->next->valid)
	{
		cur2 = cur1->next;
		while (cur2->valid)
		{
			if (cur1->num == cur2->num)
				return (FAIL);
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
	return (SUCCESS);
}
