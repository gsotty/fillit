/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:42:14 by tapperce          #+#    #+#             */
/*   Updated: 2017/01/11 07:37:40 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		return (0);
	if ((pieces = p_malloc(pieces)) == 0)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	if ((pieces = get_pieces(fd, pieces)) == 0)
		return (0);
	if ((ft_board(pieces, board, 2) == NULL))
		return (0);
	return (0);
}
