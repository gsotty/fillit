/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 04:01:59 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/11 11:22:32 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_line_len(char *str)
{
	int		x;

	x = 0;
	while (str[x] != '\0' && str[x] != '\n')
		x++;
	return (x);
}

int		ft_place(int **pieces, char *board, int pos, int nbr_pieces)
{
	int		x;
	int		y;
	int		size;

	x = 0;
	y = 0;
	size = ft_line_len(board);
	while (y < 4)
	{
		x = 0;
		while (x < pieces[y][1])
		{
			if (board[pos + x + pieces[y][0]] == '.')
			{
				board[pos + x + pieces[y][0]] = 'A' + nbr_pieces;
			}
			else
				return (0);
			x++;
		}
		pos = pos + size + 1;
		y++;
	}
	return (1);
}

int		ft_browse(int **pieces, char *board, int pos, int nbr_pieces)
{
	int		y;
	int		x;
	int		size;
	int		tmp_pos;

	x = 0;
	y = 0;
	size = ft_line_len(board);
	tmp_pos = pos;
	while (y < 4)
	{
		x = 0;
		while (x < pieces[y][1])
		{
			if (board[pos + x + pieces[y][0]] != '.')
				return (0);
			x++;
		}
		pos = pos + size + 1;
		y++;
	}
	ft_place(pieces, board, tmp_pos, nbr_pieces);
	return (1);
}

void	ft_delete_pieces(char *board, int nbr_pieces, int size)
{
	int		x;

	x = 0;
	while (x < (size * size) + size)
	{
		if (board[x] == 'A' + nbr_pieces)
			board[x] = '.';
		x++;
	}
}

int		fillit(int ***pieces, char *board, int size, int nbr_pieces)
{
	int		pos;

	pos = 0;
	if (pieces[0] == 0)
		return (1);
	while (pos < ((size * size) + size))
	{
		if (ft_browse(pieces[0], board, pos, nbr_pieces) == 1)
		{
			if (fillit(pieces + 1, board, size, nbr_pieces + 1))
			{
				return (1);
			}
			else
			{
				ft_delete_pieces(board, nbr_pieces, size);
			}
		}
		pos++;
	}
	return (0);
}
