# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/25 21:51:11 by tozaki            #+#    #+#              #
#    Updated: 2025/11/29 13:19:11 by tozaki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra
SRCS	=	push_swap.c		\
			node_add.c		\
			node_del.c		\
			rules1.c		\
			rules2.c		\
			rules3.c		\
			set_index.c		\
			sort_len3.c		\
			sort_len6.c		\
			sort_radix.c	\
			validate_input.c\
			ft_split.c		\
			utils.c
OBJS	=	$(SRCS:%.c=%.o)
HDRS	=	define.h		\
			input.h			\
			node.h			\
			sort.h			\
			utils.h

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) -o $(NAME) $(OBJS) libft/libft.a

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) -c $< -o $@

libft/libft.a:
	make -C libft all

.PHONY: clean
clean:
	make -C libft clean
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)

.PHONY: re
re: fclean all