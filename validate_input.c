/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:36:51 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/26 15:55:35 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "define.h"
#include "utils.h"

static int	is_valid_number(char *str)
{
	int	i;
	int	number_exists;

	i = 0;
	number_exists = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isnum(str[i]))
			return (0);
		number_exists = 1;
		i++;
	}
	if (!number_exists)
		return (0);
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
	int		len;
	int		i;
	int		j;

	cur1 = stack_a->next;
	len = nodelen(stack_a);
	i = 0;
	while (i < len)
	{
		j = i;
		cur2 = cur1->next;
		while (j < len)
		{
			if (cur1->num == cur2->num)
				return (FAIL);
			cur2 = cur2->next;
			j++;
		}
		cur1 = cur1->next;
		i++;
	}
	return (SUCCESS);
}
