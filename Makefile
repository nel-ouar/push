# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 01:21:47 by nel-ouar          #+#    #+#              #
#    Updated: 2024/08/13 10:33:14 by nel-ouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = free.c \
       free2.c \
       main.c \
       parcing.c \
       push.c \
       reverse_rotate.c \
       rotate.c \
       sort_big_helpers.c \
       sort_big_numbers.c \
       sort_smal_helper.c \
       sort_smal_numbers.c \
       split.c \
       swap.c \
       utils.c \
       utils2.c \
       parce_utils.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
