/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:04:23 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/24 21:55:03 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "node.h"

/*sort*/
int	issorted(t_node *dummy);
int	radix_sort_one_digit(t_node *stack_a, t_node *stack_b, int digit);
int	radix_sort(t_node *stack_a, t_node *stack_b);

#endif