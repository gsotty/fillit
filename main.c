/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:12:47 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/21 18:16:37 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int			ft_strlen_tab(char **pieces)
{
	int		x;

	x = 0;
	while (pieces[x])
	{
		x++;
	}
	return (x);
}

int			main(int argc, char **argv)
{
	int				fd;
	char			**pieces;
	int				n;
	t_boardtype		*tab_pieces;
	t_boardtype		*tab_pieces_f;

	pieces = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		pieces = ft_bin_pieces(ft_store(fd, pieces));
		n = ft_strlen_tab(pieces);
		if (!(tab_pieces = (t_boardtype *)malloc(sizeof(t_boardtype) * n + 1)))
			return (-1);
		tab_pieces = ft_conv_board_to_bin(pieces);
		tab_pieces[n++] = 0;
		if (!(tab_pieces_f = (t_boardtype *)malloc(sizeof(t_boardtype) * n)))
			return (-1);
		if (ft_fillit(tab_pieces, tab_pieces_f, n) == 0)
			return (-1);
		close(fd);
		return (0);
	}
	ft_exit(1, "usag: ./fillit source_file");
}
