/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_line_bin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:39:52 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/20 16:06:05 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./libft/libft.h"

int	ft_nbr_line_bin(t_boardtype bin_piece, int size)
{
	int	x;
	int	mask;
	int	result;

	x = 0;
	mask = 1;
	result = 0;
	mask = ((mask << size) - 1);
	if (bin_piece == 0)
		return (0);
	while (x <= size)
	{
		if ((bin_piece & mask) == 0)
		{
			result++;
		}
		mask <<= size;
		x++;
	}
	return (size - result);
}
