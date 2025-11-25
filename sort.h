/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:04:23 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/25 14:43:20 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "node.h"

typedef struct s_numbers{
	unsigned int	fir;
	unsigned int	sec;
	unsigned int	thir;
}					t_numbers;

/*sort_len3*/
int	match_pattern_len3(t_node *stack_a, t_node *stack_b, t_numbers n);
int	sort_len3(t_node *stack_a, t_node *stack_b);

/*sort_radix*/
int	issorted(t_node *dummy);
int	radix_sort_one_digit(t_node *stack_a, t_node *stack_b, int digit);
int	radix_sort(t_node *stack_a, t_node *stack_b);

#endif