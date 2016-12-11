/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:16:26 by tapperce          #+#    #+#             */
/*   Updated: 2016/12/11 17:25:37 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

t_all				*ft_browse(unsigned int bin_piece, t_all *all, int count)
{
	unsigned int	result;
	int				nb_line;
	int				amp;
	int				i;

	amp = ft_bin_amp(bin_piece);
	nb_line = ft_nbr_line_bin(bin_piece) - 1;
	bin_piece = ft_swap_board_bit(bin_piece, all->size_board);
	while ((all->size_board->size - ++nb_line) >= 0)
	{
		i = -1;
		while ((all->size_board->size - (amp + ++i)) >= 0)
		{
			if ((result = ft_fill(all->board->board, bin_piece)) != 0)
			{
				all->board->tab_piece[count] = bin_piece;
				all->board->board = result;
				return (all);
			}
			bin_piece <<= 1;
		}
		bin_piece <<= (all->size_board->size - i);
	}
	all->board->board = 0;
	return (all);
}
