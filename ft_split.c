/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:07:16 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/23 21:23:05 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_words(char *str)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 1;
	while (str[i])
	{
		if (flag == 1 && str[i] != ' ')
			count++;
		flag = 0;
		if (str[i] == ' ')
			flag = 1;
		i++;
	}
	return (count);
}

static char	*get_next_word(char **str)
{
	char	*word;
	int		i;
	int		j;
	int		start;
	int		end;

	i = 0;
	while ((*str)[i] == ' ')
		i++;
	start = i;
	while ((*str)[i] != ' ' && (*str)[i])
		i++;
	end = i;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < end)
	{
		word[j] = (*str)[j + start];
		j++;
	}
	word[end - start] = '\0';
	*str += end;
	return (word);
}

void	free_sp(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

char	**ft_split(char *str)
{
	char	**sp;
	char	*word;
	int		n;
	int		i;

	n = count_words(str);
	sp = (char **)malloc(sizeof(char *) * (n + 1));
	if (!sp)
		return (NULL);
	i = 0;
	while (i < n)
	{
		word = get_next_word(&str);
		if (!word)
		{
			free_sp(sp);
			return (NULL);
		}
		sp[i] = word;
		i++;
	}
	sp[n] = NULL;
	return (sp);
}

// #include <stdio.h>

// int main(void)
// {
// 	char	**sp;

// 	sp = ft_split("12 2 33 4");
// 	for (int i = 0; i < 4; i++)
// 		printf("%s\n", sp[i]);
// 	free_sp(sp);
// 	return (0);
// }