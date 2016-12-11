/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_end_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:02:55 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/11 16:15:14 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "stdlib.h"
#include "unistd.h"

static void	ft_putboard(char *board_finish, int size)
{
	while (*board_finish)
	{
		write(1, board_finish, size);
		write(1, "\n", 1);
		board_finish = board_finish + size;
	}
}

static char	*ft_while(t_all *all, char *board_finish)
{
	int		y;
	int		x;
	char	*board_tmp;

	x = -1;
	while (all->board->tab_piece[++x])
	{
		if (0 < all->size_board->size)
		{
			y = -1;
			board_tmp = ft_bin_to_char(all->board->tab_piece[x],
					(all->size_board->size * all->size_board->size), x - 1);
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

int			ft_put_end_board(t_all *all)
{
	char	*board_finish;

	if (!(board_finish = (char *)malloc(sizeof(char) * (all->size_board->size *
						all->size_board->size))))
		return (0);
	board_finish = 0;
	ft_putboard(ft_while(all, board_finish), all->size_board->size);
	return (0);
}
