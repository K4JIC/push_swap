/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:04:23 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/26 15:47:35 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "node.h"

typedef struct s_numbers
{
	unsigned int	fir;
	unsigned int	sec;
	unsigned int	thir;
}					t_numbers;

/*sort_greedy*/
int	assign_index(t_node *stack_a);

/*sort_len3*/
int	sort_len2(t_node *stack_a, t_node *stack_b);
int	sort_len3(t_node *stack_a, t_node *stack_b);

/*sort_len6*/
int	sort_len6(t_node *stack_a, t_node *stack_b);

/*sort_radix*/
int	issorted(t_node *dummy);
int	radix_sort(t_node *stack_a, t_node *stack_b);

#endif