# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsotty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 10:29:31 by gsotty            #+#    #+#              #
#    Updated: 2017/01/11 11:26:05 by gsotty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAG = -Wall -Wextra -Werror

LIBFT = ./libft

INCLUDES = ./includes

SRC = check_exist.c creat_board.c fillit.c ft_exit.c get_pieces.c \
	  main.c store_piece.c

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

