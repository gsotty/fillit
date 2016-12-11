/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:31:38 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/11 17:40:52 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include <stdlib.h>

static t_all	*ft_malloc_board(int nbr_piece)
{
	t_all	*all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (0);
	if (!(all->size_board = (t_size_board *)malloc(sizeof(t_size_board))))
		return (0);
	if (!(all->board = (t_board *)malloc(sizeof(t_board))))
		return (0);
	if (!(all->board->tab_piece = (unsigned int *)malloc(sizeof(unsigned int) *
					nbr_piece + 1)))
		return (0);
	all->size_board->size = 4;
	all->size_board->size_base = 4;
	all->board->board = 0;
	return (all);
}

static int		ft_tablen(unsigned int *tab_piece)
{
	int	x;

	x = 0;
	while (tab_piece[x] != 0)
	{
		x++;
	}
	return (x);
}

static t_all	*ft_while(unsigned int *tab_piece, t_all *all, int piece,
		int nbr_piece)
{
	int		pospiece;

	pospiece = 0;
	if (all->board->board == 0)
		all->board->board = tab_piece[piece];
	while (pospiece < nbr_piece)
	{
		if (pospiece == piece)
			pospiece++;
		else
		{
			all = ft_browse(tab_piece[pospiece], all, pospiece);
			if ((ft_count_bit(all->board->board, all->size_board->size *
							all->size_board->size)) == nbr_piece * 4)
				return (all);
			pospiece++;
		}
	}
	return (NULL);
}

t_all			*ft_fillit(unsigned int *tab_piece)
{
	int		piece;
	int		len_board;
	int		nbr_piece;
	t_all	*all;

	len_board = 0;
	nbr_piece = ft_tablen(tab_piece);
	all = ft_malloc_board(nbr_piece);
	while (1)
	{
		piece = 0;
		all->board->board = tab_piece[piece];
		all->board->tab_piece[piece] = all->board->board;
		while (piece < nbr_piece)
		{
			if (ft_while(tab_piece, all, piece, nbr_piece))
				return (all);
			all->board->board = 0;
			piece++;
		}
		all->size_board->size++;
	}
}
