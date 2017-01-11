/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 08:17:22 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/11 08:21:31 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

char	*creat_board(int size)
{
	int		x;
	char	*board;

	x = 0;
	if (!(board = (char *)malloc(sizeof(char *) * (size * size) + size + 1)))
		return (0);
	while (x < ((size * size) + size))
	{
		ft_memset(&board[x], '.', size);
		board[x + size] = '\n';
		x = (x + size + 1);
	}
	board[(size * size) + size - 1] = '\0';
	return (board);
}
