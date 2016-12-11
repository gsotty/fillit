# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsotty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 10:29:31 by gsotty            #+#    #+#              #
#    Updated: 2016/12/11 18:02:31 by gsotty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAG = -Wall -Wextra -Werror

LIBFT = ./libft

SRC = main_test.c ft_bin_amp.c ft_bin_pieces.c ft_bin_to_char.c \
	  ft_browse.c ft_char_to_bin.c ft_conv_board_to_bin.c ft_count_bit.c \
	  ft_fill.c ft_fillit.c ft_nbr_line_bin.c ft_put_end_board.c \
	  ft_store.c ft_swap_board_bit.c ft_test_bin.c ft_verif.c

INCLUDES = ./includes

all: $(NAME)

$(NAME):
	make re -C $(LIBFT)
	$(CC) $(FLAG) $(SRC) -I $(INCLUDES) -o $(NAME) -L ./libft -lft

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -rf *.o

fclean: clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

re: fclean all

