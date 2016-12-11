/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:48:15 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/11 16:17:21 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

int				ft_count_bit(unsigned int board, int nbbits)
{
	int				i;
	int				count;
	unsigned int	bit;
	unsigned int	mask;

	i = 0;
	bit = 0;
	mask = 1;
	count = 0;
	while (i < nbbits)
	{
		bit = (board & mask) >> i;
		if (bit == 1)
			count++;
		mask <<= 1;
		i++;
	}
	return (count);
}
