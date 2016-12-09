/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:37:17 by tapperce          #+#    #+#             */
/*   Updated: 2016/12/09 14:43:38 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

#include <stdlib.h>

int				ft_count_bit(unsigned int board, int nbbits)
{
	int				i;
	int				count;
	unsigned int	bit;
	unsigned int	mask;

	i = 0;
	bit = 0;
	mask = 1;
	count = 0;
	while (i < nbbits)
	{
		bit = (board & mask) >> i;
		if (bit == 1)
			count++;
		mask <<= 1;
		i++;
	}
	return (count);
}

unsigned int	ft_fill(unsigned int dest, unsigned int src)
{
	unsigned int	cp_src;
	unsigned int	board_tmp;
	unsigned int	bit_null;

	bit_null = 1;
	cp_src = src;
	bit_null = (src & dest);
	board_tmp = (src | dest);
	ft_putnbr(bit_null);
	ft_putstr("\n");
	ft_putstr("bit_null = ");
	ft_putstr(ft_print_bit(bit_null, 5 * 5));
	ft_putstr("\n");
	if (bit_null != 0)
		return (0);
	return (board_tmp);
}

t_all			*ft_fillit(unsigned int *tab_piece)
{
	int				a;
	int				y;
	int				i;
	int				j;
	int				x;
	int				z;
	t_all			*all;

	a = -1;
	x = 0;
	i = 0;
	y = 0;
	z = 0;
	j = 0;
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (0);
	if (!(all->size_board = (t_size_board *)malloc(sizeof(t_size_board))))
		return (0);
	all->size_board->size = 3;
	all->size_board->size_base = 4;
	if (!(all->board = (t_board *)malloc(sizeof(t_board))))
		return (0);
	all->board->board = 0;
	if (!(all->board->board_tmp = (unsigned int *)malloc(sizeof(unsigned int)
					* 26)))
		return (0);
	while (tab_piece[x] != 0)
	{
		all->board->board_tmp[x] = tab_piece[x];
		x++;
	}
	if (!(all->board->tab_piece = (unsigned int *)malloc(sizeof(unsigned int)
					* x + 1)))
		return (0);
	while (a < x)
	{
		z = 0;
		y = 0;
		a++;
		all->size_board->size++;
		ft_putstr("						111\n");
		while (y < x)
		{
			i = 0;
			all->board->board = tab_piece[z];
			while (i < (x - 1))
			{
				if (i == z)
					i++;
				if (!(all->board = browse(tab_piece[i], all, i)))
					i++;
				else if ((ft_count_bit(all->board->board,
				all->size_board->size * all->size_board->size)) == (x * 4))
				{
					while (all->board->tab_piece[x])
					{
						tab_piece[i] = 0;
						x++;
					}
					return (all);
				}
				i++;
			}
			z++;
			y++;
		}
	}
	return (0);
}
