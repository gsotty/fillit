/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:16:26 by tapperce          #+#    #+#             */
/*   Updated: 2016/12/20 16:39:56 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "libft/libft.h"

int		ft_browse(t_boardtype *tab_pieces, t_boardtype tab_pieces_tmp,
		const int size)
{
	t_boardtype		mask;
	t_boardtype		pieces;
	int				nbr_line;
	int				amp;
	int				i;

	mask = 1;
	mask = ((mask << (size * size)) - 1);
	pieces = mask & ft_swap_board_bit(tab_pieces[0], size);
	amp = ft_bin_amp(tab_pieces_tmp, size);
	nbr_line = ft_nbr_line_bin(tab_pieces_tmp, size);
	while ((size - nbr_line) >= 0)
	{
		i = 0;
		while ((size - (amp + i)) >= 0)
		{
			if (tab_pieces_tmp == pieces)
				return (1);
			pieces <<= 1;
			i++;
		}
		pieces <<= (size - i);
		nbr_line++;
	}
	return (0);
}
