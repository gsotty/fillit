/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_amp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:37:18 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/10 15:51:03 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

int		ft_bin_amp(unsigned int bin_piece)
{
	int	mask;
	int	result;

	result = 0;
	mask = 34952;
	if (bin_piece == 0)
		return (0);
	while ((bin_piece & mask) == 0)
	{
		mask >>= 1;
		result++;
	}
	return (4 - result);
}
