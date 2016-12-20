/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_amp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:37:18 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/20 10:33:48 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./libft/libft.h"

int		ft_bin_amp(t_boardtype bin_piece, int size)
{
	int			i;
	int			x;
	t_boardtype	mask;
	int			result;

	i = 0;
	x = 0;
	if (bin_piece == 0 || size == 0)
		return (0);
	result = 0;
	mask = 0;
	while (x < size)
	{
	//	ft_putstr("111\n");
		mask += 1 << i;
		i += size;
		x++;
	}
	x = 0;
	while (x < size)
	{
	//	ft_putstr("222\n");
		if ((bin_piece & mask) == 0)
		{
			result++;
		}
		mask <<= 1;
		x++;
	}
	return (size - result);
}
