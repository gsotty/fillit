/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_amp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:37:18 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/21 17:29:16 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./libft/libft.h"

int		ft_bin_amp(t_boardtype bin_piece, int size)
{
	int			i;
	int			x;
	t_boardtype	tmp;
	t_boardtype	mask;
	int			result;

	i = 0;
	x = 0;
	tmp = 1;
	mask = 0;
	result = 0;
	while (x < size)
	{
		mask += tmp << i;
		i += size;
		x++;
	}
	x = -1;
	while (++x < size)
	{
		if ((bin_piece & mask) == 0)
			result++;
		mask <<= 1;
	}
	return (size - result);
}
