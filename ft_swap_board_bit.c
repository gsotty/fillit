/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_board_bit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:40:56 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/21 17:54:19 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./libft/libft.h"

t_boardtype		ft_while_inf(t_boardtype mask, int size, t_boardtype bit)
{
	int				x;
	t_boardtype		tmp_bit;
	t_boardtype		new_bit;

	x = 0;
	tmp_bit = bit;
	new_bit = bit;
	while (x < 4)
	{
		tmp_bit = tmp_bit & mask;
		tmp_bit >>= (4 - size);
		new_bit = (tmp_bit | (new_bit & ~mask));
		mask <<= size;
		x++;
	}
	return (new_bit);
}

t_boardtype		ft_while_sup(t_boardtype mask, int size, t_boardtype bit)
{
	int				x;
	t_boardtype		tmp_bit;
	t_boardtype		new_bit;

	x = 0;
	tmp_bit = bit;
	new_bit = bit;
	while (x < size)
	{
		tmp_bit = tmp_bit & mask;
		tmp_bit <<= (size - 4);
		new_bit = (tmp_bit | (new_bit & ~mask));
		mask <<= size;
		x++;
	}
	return (new_bit);
}

t_boardtype		ft_swap_board_bit(t_boardtype bit, int size)
{
	t_boardtype		mask;
	t_boardtype		new_bit;

	mask = 1;
	mask = (((mask << 16) - 1) - ((mask << 4) - 1)) |
		(((mask << (size * size)) - 1) - ((mask << size) - 1));
	if (bit == 0)
		return (0);
	if (size < 4)
		return (ft_while_inf(mask, size, bit));
	else
		return (ft_while_sup(mask, size, bit));
	return (new_bit);
}
