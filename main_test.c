/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:05:34 by tapperce          #+#    #+#             */
/*   Updated: 2016/12/11 16:39:47 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_all	*ft_malloc(unsigned int *tab_pieces, int i, char **pieces)
{
	t_all	*tab_finish;

	if (!(tab_pieces = (unsigned int *)malloc(sizeof(unsigned int)
					* i + 1)))
		return (NULL);
	if ((tab_pieces = ft_conv_board_to_bin(pieces)) == NULL)
		return (NULL);
	tab_pieces[i] = 0;
	if ((tab_finish = ft_fillit(tab_pieces)) == 0)
		return (NULL);
	return (tab_finish);
}

int				main(int argc, char **argv)
{
	char			**pieces;
	unsigned int	*tab_pieces;
	int				i;
	int				fd;

	i = 0;
	fd = 0;
	tab_pieces = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		pieces = ft_bin_pieces(ft_store(fd));
		while (pieces[i])
			i++;
		ft_put_end_board(ft_malloc(tab_pieces, i, pieces));
		if (close(fd) == -1)
			return (-1);
	}
	return (0);
}
