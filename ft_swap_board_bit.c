/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_board_bit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:40:56 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/09 13:43:36 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

unsigned int		ft_swap_board_bit(unsigned int bit, t_size_board *size_board)
{
	int				x;
	int				tmp;
	unsigned int	mask;
	unsigned int	tmp_bit;
	unsigned int	new_bit;

	x = 0;
	mask = bit;
	if ((bit = ft_verif(bit)) == 0)
		bit = mask;
	new_bit = bit;
	tmp_bit = bit;
	tmp = size_board->size_base;
	mask = ((ft_pow(2, (tmp * tmp)) - 1) - (ft_pow(2, tmp) - 1));
	while (x < size_board->size)
	{
		tmp_bit = tmp_bit & mask;
		tmp_bit <<= (size_board->size - tmp);
		new_bit = (tmp_bit | (new_bit & ~mask));
		mask <<= tmp;
		x++;
	}
	return (new_bit);
}
