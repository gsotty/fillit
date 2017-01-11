/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:31:37 by tapperce          #+#    #+#             */
/*   Updated: 2017/01/11 08:06:00 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		store_piece(char *buf, int **pieces)
{
	int		i;
	int		j;
	int		first;
	int		origin;
	int		nb_block;

	i = -1;
	j = 0;
	origin = -1;
	if (check_syntax(buf) == 0)
		return (0);
	while (buf[++i])
	{
		nb_block = 0;
		first = 0;
		while ((i + 1) % 5 != 0)
		{
			if (buf[i] == '#')
			{
				if (nb_block == 0)
					first = ((i + 1) % 5) - 1;
				if (nb_block == 0 && origin == -1)
					origin = ((i + 1) % 5) - 1;
				nb_block++;
			}
			i++;
		}
		if (nb_block != 0)
		{
			pieces[j][0] = first - origin;
			pieces[j][1] = nb_block;
			j++;
		}
	}
	if (check_exist_0(pieces) == 0)
		return (0);
	return (1);
}
