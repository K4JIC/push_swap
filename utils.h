/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:56:08 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/26 14:17:17 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*utils*/
int		ft_isnum(char c);
int		ft_atoi(char *str);
long	ft_atol(char *str);

/*split*/
int		count_words(char *str);
char	**ft_split(char *str);
void	free_sp(char **sp);

#endif
