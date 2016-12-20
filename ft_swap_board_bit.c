/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_board_bit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:40:56 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/20 16:01:17 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./libft/libft.h"

t_boardtype		ft_swap_board_bit(t_boardtype bit, int size)
{
	int				x;
	t_boardtype		mask;
	t_boardtype		tmp_bit;
	t_boardtype		new_bit;

	x = 0;
	mask = 1;
	new_bit = bit;
	tmp_bit = bit;
	if (bit == 0)
		return (0);
	if (size < 4)
	{
		mask = (((mask << 16) - 1) - ((mask << 4) - 1)) |
			(((mask << (size * size)) - 1) - ((mask << size) - 1));
		while (x < 4)
		{
			tmp_bit = tmp_bit & mask;
			tmp_bit >>= (4 - size);
			new_bit = (tmp_bit | (new_bit & ~mask));
			mask <<= size;
			x++;
		}
	}
	else
	{
		mask = (((mask << 16) - 1) - ((mask << 4) - 1)) |
			(((mask << (size * size)) - 1) - ((mask << size) - 1));
		while (x < size)
		{
			tmp_bit = tmp_bit & mask;
			tmp_bit <<= (size - 4);
			new_bit = (tmp_bit | (new_bit & ~mask));
			mask <<= size;
			x++;
		}
	}
	return (new_bit);
}
