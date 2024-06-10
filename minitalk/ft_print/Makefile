# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salaoui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 09:28:46 by salaoui           #+#    #+#              #
#    Updated: 2023/12/26 15:43:07 by salaoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putbase.c ft_putstr.c ft_pointer.c ft_strchr.c 

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC_o := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_o)
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(SRC_o)

clean:
	rm -f $(SRC_o)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: