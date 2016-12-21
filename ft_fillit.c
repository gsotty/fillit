/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:34:11 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/21 18:06:11 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

int				ft_remp(t_boardtype tab_pieces, t_boardtype *board)
{
	t_boardtype	bit_null;

	bit_null = 0;
	bit_null = tab_pieces & *board;
	if (bit_null != 0)
		return (0);
	else
	{
		*board = tab_pieces | *board;
		return (1);
	}
}

int				ft_fill(t_boardtype *tab_pieces, t_boardtype *board, int size,
		t_boardtype *tab_pieces_finish)
{
	int			x;
	t_boardtype	tab_pieces_tmp;
	t_boardtype	comp;

	comp = 1;
	comp = ((comp << (size * size)) - 1);
	tab_pieces_tmp = ft_swap_board_bit(tab_pieces[0], size);
	if ((x = -1) && tab_pieces[0] == 0)
		return (1);
	while ((tab_pieces_tmp <= comp) && (++x < (size * size)))
	{
		if ((ft_browse(tab_pieces, tab_pieces_tmp, size) == 1)
				&& (ft_remp(tab_pieces_tmp, board) == 1))
		{
			if (ft_fill(tab_pieces + 1, board, size, tab_pieces_finish + 1))
			{
				tab_pieces_finish[0] = tab_pieces_tmp;
				return (1);
			}
			else
				*board = ~tab_pieces_tmp & *board;
		}
		tab_pieces_tmp <<= 1;
	}
	return (0);
}

int				ft_board(t_boardtype *tab_pieces, t_boardtype *board, int size,
		t_boardtype *tab_pieces_finish)
{
	*board = 0;
	if (ft_fill(tab_pieces, board, size, tab_pieces_finish) == 1)
	{
		ft_put_end_board(tab_pieces_finish, size);
		ft_exit(0, "terminer");
	}
	else
	{
		*board = ft_swap_board_bit(*board, size);
		ft_board(tab_pieces, board, size + 1, tab_pieces_finish);
		return (size);
	}
	return (size);
}

int				ft_fillit(t_boardtype *tab_pieces,
		t_boardtype *tab_pieces_finish, int nbr_pieces)
{
	int			x;
	int			size;
	t_boardtype	board;

	x = 1;
	board = 1;
	while ((nbr_pieces * 4) >= (x * x))
	{
		size = x;
		x++;
	}
	size = ft_board(tab_pieces, &board, size, tab_pieces_finish);
	return (size);
}
