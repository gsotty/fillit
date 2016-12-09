/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:05:34 by tapperce          #+#    #+#             */
/*   Updated: 2016/12/09 14:13:45 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int				ft_printboard(t_all *all)
{
	int		x;
	int		i;
	int		y;
	char	*board_tmp;
	char	*board_finish;

	x = 0;
	i = 0;
	y = 0;
	if (!(board_finish = (char *)malloc(sizeof(char) * (all->size_board->size *
						all->size_board->size))))
		return (0);
	board_finish = 0;
	while (all->board->tab_piece[x])
	{
		ft_putstr("tab_piece 1 = ");
		ft_putstr(ft_print_bit(all->board->tab_piece[x],
				all->size_board->size * all->size_board->size));
		ft_putstr("\n");
		ft_swap_board_bit(all->board->tab_piece[x], all->size_board);
		ft_putstr("tab_piece2 = ");
		ft_putstr(ft_print_bit(all->board->tab_piece[x],
				all->size_board->size * all->size_board->size));
		ft_putstr("\n");
		x++;
	}
	x = 0;
	while (all->board->tab_piece[x])
	{
		if (i < all->size_board->size)
		{
			y = 0;
			board_tmp = ft_printbit(all->board->tab_piece[x],
					all->size_board->size * all->size_board->size, x - 1);
			if (board_finish == 0)
				board_finish = board_tmp;
			else
			{
				while (board_tmp[y])
				{
					if (board_finish[y] == '.')
						board_finish[y] = board_tmp[y];
					y++;
				}
			}
		}
		x++;
	}
	while (*board_finish)
	{
		write(1, board_finish, all->size_board->size);
		write(1, "\n", 1);
		board_finish = board_finish + all->size_board->size;
	}
	return (0);
}

unsigned int	*ft_conv(char **tab)
{
	int				x;
	unsigned int	*tab_int;

	x = 0;
	while (tab[x])
		x++;
	if (!(tab_int = (unsigned int *)malloc(sizeof(unsigned int) * x + 1)))
		return (NULL);
	ft_bzero(tab_int, x + 1);
	x = 0;
	while (tab[x])
	{
		if ((tab_int[x] = ft_verif(ft_bits(tab[x]))) == 0)
			return (NULL);
		x++;
	}
	tab[x] = 0;
	return (tab_int);
}

int				main(int argc, char **argv)
{
	char			**pieces;
	unsigned int	*tab_pieces;
	int				i;
	int				fd;
	t_all			*tab_finish;

	i = 0;
	fd = 0;
	tab_pieces = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		pieces = bin_pieces(store(fd));
		while (pieces[i])
			i++;
		if (!(tab_pieces = (unsigned int *)malloc(sizeof(unsigned int) * i + 1)))
			return (-1);
		if ((tab_pieces = ft_conv(pieces)) == NULL)
			return (-1);
		tab_pieces[i] = 0;
		if ((tab_finish = ft_fillit(tab_pieces)) == 0)
			return (-1);
		ft_printboard(tab_finish);
		if (close(fd) == -1)
			return (-1);
	}
	return (0);
}
