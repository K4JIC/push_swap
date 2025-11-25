/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:28:17 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/25 21:37:45 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

#include "node.h"

int	is_valid_number(char *str);
int	validate_atoi(char *str, int *n);
int	check_duplicate(t_node *stack_a);

#endif