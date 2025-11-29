# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 13:00:34 by tozaki            #+#    #+#              #
#    Updated: 2025/11/29 17:50:33 by tozaki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	=	server
CLIENT	=	client
CC		=	cc
FALGS	=	-Wall -Wextra -Werror
S_SRCS	=	server.c
C_SRCS	=	client.c
S_OBJS	=	server.o
C_OBJS	=	client.o
S_HDRS	=	server.h


.PHONY: all
all: $(SERVER) $(CLIENT)

$(SERVER): $(S_OBJS) ft_printf/libftprintf.a
	$(CC) $(S_OBJS) -o $(SERVER) ft_printf/libftprintf.a

$(CLIENT): $(C_OBJS) ft_printf/libftprintf.a
	$(CC) $(C_OBJS) -o $(CLIENT) ft_printf/libftprintf.a

$(S_OBJS): $(S_SRCS) $(S_HDRS)
	$(CC) $(FALGS) $(S_SRCS) -c

$(C_OBJS): $(C_SRCS)
	$(CC) $(FALGS) $(C_SRCS) -c

ft_printf/libftprintf.a:
	make -C ft_printf all

.PHONY: clean
clean:
	make -C ft_printf clean
	rm -f $(S_OBJS)
	rm -f $(C_OBJS)

.PHONY: fclean
fclean: clean
	rm -f ft_printf/libftprintf.a
	rm -f server
	rm -f client

.PHONY: re
re: fclean all