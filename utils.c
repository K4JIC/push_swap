/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:37:33 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/23 21:42:24 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isnum(char c)
{
	if ('0' <= c && c  <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		sign;
	long	ln;
	int		i;

	sign = 1;
	ln = 0;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isnum(str[i]))
	{
		ln = ln * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(sign * ln));
}


