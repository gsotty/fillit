/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:31:37 by tapperce          #+#    #+#             */
/*   Updated: 2017/01/11 13:46:11 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_while(int *i, int *first, int *origin, char *buf)
{
	int		tmp_i;
	int		nb_block;

	tmp_i = *i;
	nb_block = 0;
	while ((tmp_i + 1) % 5 != 0)
	{
		if (buf[tmp_i] == '#')
		{
			if (nb_block == 0)
				*first = ((tmp_i + 1) % 5) - 1;
			if (nb_block == 0 && *origin == -1)
				*origin = ((tmp_i + 1) % 5) - 1;
			nb_block++;
		}
		tmp_i++;
	}
	*i = tmp_i;
	return (nb_block);
}

int		store_piece(char *buf, int **pieces)
{
	int		i;
	int		j;
	int		first;
	int		origin;
	int		nb_block;

	j = 0;
	i = -1;
	origin = -1;
	while (buf[++i] && (!(first = 0)))
	{
		nb_block = ft_while(&i, &first, &origin, buf);
		if (nb_block != 0)
		{
			pieces[j][0] = first - origin;
			pieces[j][1] = nb_block;
		}
		if (nb_block != 0 || j != 0)
			j++;
	}
	return (1);
}
