/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_line_bin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:39:52 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/10 15:52:13 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

int	ft_nbr_line_bin(unsigned int bin_piece)
{
	if (bin_piece > 0 && bin_piece <= 15)
		return (1);
	else if (bin_piece >= 16 && bin_piece <= 255)
		return (2);
	else if (bin_piece >= 256 && bin_piece <= 4095)
		return (3);
	else if (bin_piece >= 4096 && bin_piece <= 65535)
		return (4);
	else
		return (-1);
}
