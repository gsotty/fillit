# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsotty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 10:29:31 by gsotty            #+#    #+#              #
#    Updated: 2016/12/09 14:05:59 by gsotty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = exec

NAME = fillit

CC = gcc

FLAG = -g -Wall -Wextra -Werror

LIBFT = ./libft

SRC = main_test.c bin_pieces.c ft_bits.c ft_verif.c store.c \
	browse.c printbits.c ft_swap_board_bit.c fillit.c \
	printbits\ 2.c

INCLUDES = ./includes

all: $(EXEC)

exec:
	make -C $(LIBFT)
	$(CC) $(FLAG) $(SRC) -I $(INCLUDES) -o $(NAME) -L ./libft -lft

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

