/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:28:17 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/26 16:01:15 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "node.h"

/*validate_input*/
int	validate_atoi(char *str, int *n);
int	check_duplicate(t_node *stack_a);

#endif