# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 19:58:38 by tozaki            #+#    #+#              #
#    Updated: 2025/11/15 20:48:44 by tozaki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	cc
FLAG	=	-Wall -Werror -Wextra
SRCS 	= 	ft_printf.c
MAIN	=	main.c
OBJS 	= 	ft_printf.o
HDR 	= 	ft_printf.h

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HDR)
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: run
run: libft/libft.a
	$(CC) $(FLAG) $(SRCS) $(MAIN) $(HDR) -I libft -L libft -lft
	./a.out

libft/libft.a:
	make -C libft all
	make -C libft clean

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

