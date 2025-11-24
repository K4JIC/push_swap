/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:40:40 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/23 21:39:46 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_node{
	int				num;
	bool			valid;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/*node_add*/
t_node	*init_node();
t_node	*node_new(int num);
t_node	*node_last(t_node *dummy);
t_node	*node_add_back(t_node *dummy, t_node *new);
t_node	*node_add_front(t_node *dummy, t_node *new);

/*node_pop*/
t_node	*node_pop(t_node **dummy);
void	free_node(t_node *dummy);

/*rules*/
int	pa(t_node *stack_a, t_node *stack_b);
int	pb(t_node *stack_a, t_node *stack_b);

#endif
