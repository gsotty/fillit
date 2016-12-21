# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsotty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 10:29:31 by gsotty            #+#    #+#              #
#    Updated: 2016/12/21 16:53:29 by gsotty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAG = -Wall -Wextra -Werror

LIBFT = ./libft

INCLUDES = ./includes

SRC = main.c ft_bin_amp.c ft_bin_pieces.c ft_bin_to_char.c \
	  browse.c ft_char_to_bin.c ft_conv_board_to_bin.c \
	  ft_fillit.c ft_nbr_line_bin.c ft_put_end_board.c \
	  ft_store.c ft_swap_board_bit.c ft_test_bin.c ft_verif.c \
	  ft_exit.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	make re -C $(LIBFT)
	$(CC) $(FLAG) $(SRC) -I $(INCLUDES) -o $(NAME) -L ./libft -lft

debug: $(OBJ)
	make re -C $(LIBFT)
	make clean -C $(LIBFT)
	$(CC) -g $(FLAG) $(SRC) -I $(INCLUDES) -o $(NAME) -L ./libft -lft

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJ)

declean:
	make clean -C $(LIBFT)
	rm -Rf $(NAME).dSYM
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

re: fclean all

