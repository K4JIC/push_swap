/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:12:33 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/26 16:00:19 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned char	ucc;

	ucc = (unsigned char)c;
	if (c == EOF)
		return (0);
	if (ft_isalpha(ucc) || ft_isdigit(ucc))
		return (1);
	return (0);
}

// #ifdef TEST
// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	char	charset[] = {
// 		'c',
// 		'a',
// 		'z',
// 		254,
// 		255,
// 		-1,
// 		0
// 	};
// 	int	len = ft_strlen(charset);
// 	for (int	i = 0; i < len; i++)
// 	{
// 		printf("output  : %d\n", ft_isalnum(charset[i]));
// 		printf("expected: %d\n\n", isalnum(charset[i]));
// 	}
// }

// #endif