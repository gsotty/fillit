/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_end_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:02:55 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/20 16:23:21 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "stdlib.h"
#include "unistd.h"

#include "./libft/libft.h"

static void	ft_putboard(char *board_finish, int size)
{
	while (*board_finish)
	{
		write(1, board_finish, size);
		write(1, "\n", 1);
		board_finish = board_finish + size;
	}
}

static char	*ft_while(t_boardtype *tab_pieces_finish, char *board_finish,
		int size)
{
	int		y;
	int		x;
	char	*board_tmp;

	x = -1;
	while (tab_pieces_finish[++x])
	{
		if (0 < size)
		{
			y = -1;
			board_tmp = ft_bin_to_char(tab_pieces_finish[x], (size * size),
					x - 1);
			if (board_finish == 0)
				board_finish = board_tmp;
			else
			{
				while (board_tmp[++y])
				{
					if (board_finish[y] == '.')
						board_finish[y] = board_tmp[y];
				}
			}
		}
	}
	return (board_finish);
}

int			ft_put_end_board(t_boardtype *tab_pieces_finish, int size)
{
	char	*board_finish;

	if (!(board_finish = (char *)malloc(sizeof(char) * (size * size))))
		return (0);
	board_finish = 0;
	ft_putboard(ft_while(tab_pieces_finish, board_finish, size), size);
	return (0);
}
