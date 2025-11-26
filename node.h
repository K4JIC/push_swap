/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:40:40 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/26 15:54:53 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include <stdbool.h>
# include <unistd.h>

typedef struct s_node
{
	unsigned int	num;
	unsigned int	index;
	bool			valid;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/*node_add*/
t_node	*init_node(void);
t_node	*node_new(int num);
t_node	*node_last(t_node *dummy);
t_node	*node_add_back(t_node *dummy, t_node *new);
t_node	*node_add_front(t_node *dummy, t_node *new);

/*node_del*/
int		nodelen(t_node *dummy);
t_node	*node_pop(t_node **dummy);
void	free_node(t_node *dummy);

/*rules1*/
int		sa(t_node *stack_a, t_node *stack_b);
int		sb(t_node *stack_a, t_node *stack_b);
int		pa(t_node *stack_a, t_node *stack_b);
int		pb(t_node *stack_a, t_node *stack_b);
/*rules2*/
int		ra(t_node *stack_a, t_node *stack_b);
int		rb(t_node *stack_a, t_node *stack_b);
int		rra(t_node *stack_a, t_node *stack_b);
int		rrb(t_node *stack_a, t_node *stack_b);
/*rules3*/
int		ss(t_node *stack_a, t_node *stack_b);
int		rr(t_node *stack_a, t_node *stack_b);
int		rrr(t_node *stack_a, t_node *stack_b);

#endif
