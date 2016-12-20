/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:12:47 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/19 12:30:17 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int			main(int argc, char **argv)
{
	int				size;
	int				x;
	int				fd;
	char			**pieces;
	t_boardtype		*tab_pieces;
	t_boardtype		*tab_pieces_finish;

	x = 0;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		if (!(pieces = ft_bin_pieces(ft_store(fd))))
			return (-1);
		while (pieces[x])
			x++;
		if (!(tab_pieces = (t_boardtype *)malloc(sizeof(t_boardtype) * x + 1)))
			return (-1);
		if ((tab_pieces = ft_conv_board_to_bin(pieces)) == NULL)
			return (-1);
		tab_pieces[x] = 0;
		if (!(tab_pieces_finish = (t_boardtype *)malloc(sizeof(t_boardtype)
						* x + 1)))
			 return (0);
		tab_pieces_finish[x + 1] = 0;
		if ((size = ft_fillit(tab_pieces, tab_pieces_finish, x)) == 0)
			return (-1);
		if (close(fd) == -1)
			return (-1);
		return (0);
	}
	ft_putstr("usag: ./fillit source_file\n");
	return (0);
}
