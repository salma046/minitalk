# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 20:34:01 by salaoui           #+#    #+#              #
#    Updated: 2024/05/06 12:18:41 by salaoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCC = client.c minitalk_utils.c
SRCS = server.c

LIBRARY = libftprintf.a

SRCCB = client_bonus.c minitalk_utils.c
SRCSB = server_bonus.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
SNAME = server
CNAME = client
SBNAME = server_bonus
CBNAME = client_bonus

SRCC_o := $(SRCC:.c=.o)
SRCS_o := $(SRCS:.c=.o)
SRCCB_o := $(SRCCB:.c=.o)
SRCSB_o := $(SRCSB:.c=.o)

all: $(SNAME) $(CNAME)

bonus: $(SBNAME) $(CBNAME)

$(CNAME) $(SNAME): $(SRCC_o) $(SRCS_o)
	$(CC) $(CFLAGS) -o $(CNAME) $(SRCC_o) $(LIBRARY)
	$(CC) $(CFLAGS) -o $(SNAME) $(SRCS_o) $(LIBRARY)

$(CBNAME) $(SBNAME): $(SRCCB_o) $(SRCSB_o)
	$(CC) $(CFLAGS) -o $(CBNAME) $(SRCCB_o) $(LIBRARY)
	$(CC) $(CFLAGS) -o $(SBNAME) $(SRCSB_o) $(LIBRARY)

clean:
	rm -f $(SRCC_o) $(SRCS_o)
	rm -f $(SRCCB_o) $(SRCSB_o)

fclean: clean
	rm -f $(SNAME) $(CNAME)
	rm -f $(SBNAME) $(CBNAME)

re: fclean all bonus

.SECONDARY: $(SRCC_o) $(SRCS_o) $(SRCCB_o) $(SRCSB_o)
