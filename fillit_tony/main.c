/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:42:14 by tapperce          #+#    #+#             */
/*   Updated: 2017/01/11 11:40:11 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_board(int ***pieces, char *board, int size)
{
	if (!(board = creat_board(size)))
		ft_exit(1, "error");
	if (fillit(pieces, board, size, 0) == 1)
	{
		ft_putstr(board);
		ft_putstr("\n");
		ft_exit(0, "1");
	}
	else
	{
		ft_board(pieces, board, size + 1);
		ft_exit(1, "error");
	}
	ft_exit(1, "error");
	return (0);
}

int		***p_malloc(int ***pieces)
{
	int		i;
	int		j;

	i = 0;
	if (!(pieces = ft_memalloc(sizeof(*pieces) * 27)))
		return (NULL);
	while (i < 27)
	{
		j = 0;
		if (!(pieces[i] = ft_memalloc(sizeof(**pieces) * 4)))
			return (NULL);
		while (j < 4)
		{
			if (!(pieces[i][j] = ft_memalloc(sizeof(***pieces) * 2)))
				return (NULL);
			j++;
		}
		i++;
	}
	return (pieces);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		***pieces;
	char	*board;

	board = NULL;
	pieces = (NULL);
	if (argc != 2)
		ft_exit(1, "error");
	if ((pieces = p_malloc(pieces)) == 0)
		ft_exit(1, "error");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_exit(1, "error");
	if ((pieces = get_pieces(fd, pieces)) == 0)
		ft_exit(1, "error");
	ft_board(pieces, board, 2);
	return (0);
}
