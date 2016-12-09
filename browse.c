/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:16:26 by tapperce          #+#    #+#             */
/*   Updated: 2016/12/09 14:52:27 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

int			ft_binamp(unsigned int bin_piece)
{
	int		mask;
	int		x;
	int		result;

	x = 0;
	result = 0;
	mask = 34952;
	while ((x = bin_piece & mask) == 0)
	{
		mask >>= 1;
		result++;
	}
	return (4 - result);
}

int				ft_nbline(unsigned int bin_piece)
{
	if (bin_piece > 0 && bin_piece <= 15)
		return (1);
	else if (bin_piece >= 16 && bin_piece <= 255)
		return (2);
	else if (bin_piece >= 256 && bin_piece <= 4095)
		return (3);
	else if (bin_piece >= 4096 && bin_piece <= 65535)
		return (4);
	else
		return (-1);
}

t_board		*browse(unsigned int bin_piece, t_all *all, int count)
{
	unsigned int	result;
	int				nb_line;
	int				amp;
	int				i;

	ft_putstr("tab_piece 2 = ");
	ft_putnbr(count);
	ft_putstr(" ");
	ft_putstr(ft_print_bit(all->board->tab_piece[count], 5*5));
	ft_putstr("\n");
	amp = ft_binamp(bin_piece);
	nb_line = ft_nbline(bin_piece);
	bin_piece = ft_swap_board_bit(bin_piece, all->size_board);
	all->board->tab_piece[count] = bin_piece;
	ft_putstr("tab_piece 3 = ");
	ft_putnbr(count);
	ft_putstr(" ");
	ft_putstr(ft_print_bit(all->board->tab_piece[count], 5*5));
	ft_putstr("\n");
	while ((all->size_board->size - nb_line) >= 0)
	{
		i = 0;
		while ((all->size_board->size - amp) >= 0)
		{
		//	ft_putstr("tab_piece 6 = ");
		//	ft_putnbr(count);
		//	ft_putstr(" ");
		//	ft_putstr(ft_print_bit(all->board->tab_piece[count], 5*5));
		//	ft_putstr("\n");
				ft_putstr("bin_piece 2 = ");
				ft_putstr(ft_print_bit(bin_piece, 5*5));
				ft_putstr("\n");
				ft_putstr("board 2 = ");
				ft_putstr(ft_print_bit(all->board->board, 5*5));
				ft_putstr("\n");
			if ((result = ft_fill(all->board->board, bin_piece)) != 0)
			{
				ft_putstr("bin_piece 1 = ");
				ft_putstr(ft_print_bit(bin_piece, 5*5));
				ft_putstr("\n");
				all->board->tab_piece[count] = bin_piece;
				all->board->board = result;
				ft_putstr("tab_piece 4 = ");
				ft_putnbr(count);
				ft_putstr(" ");
				ft_putstr(ft_print_bit(all->board->tab_piece[count], 5*5));
				ft_putstr("\n");
				return (all->board);
			}
			bin_piece <<= 1;
			amp++;
			i++;
		}
		amp = amp - i;
		//bin_piece = all->board->board_tmp[count];
		bin_piece = all->board->tab_piece[count];
	//	bin_piece >>= i;
		bin_piece <<= all->size_board->size;
		nb_line++;
	}
	all->board->board = 0;
	ft_putstr("tab_piece 5 = ");
	ft_putnbr(count);
	ft_putstr(" ");
	ft_putstr(ft_print_bit(all->board->tab_piece[count], 5*5));
	ft_putstr("\n");
	return (all->board);
}
/*
   int				main(void)
   {
   unsigned int	x;
   int				n;
   int				n_base;
   unsigned int	test;
   unsigned int	board_tmp;

   n = 4;
   n_base = 4;
   x = 4369;
   board_tmp = 54;
   board_tmp = ft_swap_board_bit(board_tmp, n, n_base);
   test = browse(x, n, n_base,  board_tmp);
   ft_putstr(ft_printbit(test, (n * n)));
   ft_putstr("\n");
   return (0);
   }*/
