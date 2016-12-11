/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:51:22 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/11 16:14:57 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

unsigned int		ft_fill(unsigned int dest, unsigned int src)
{
	unsigned int	cp_src;
	unsigned int	board_tmp;
	unsigned int	bit_null;

	bit_null = 1;
	cp_src = src;
	bit_null = (src & dest);
	board_tmp = (src | dest);
	if (bit_null != 0)
		return (0);
	return (board_tmp);
}
