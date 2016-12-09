/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:56:08 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/09 11:01:49 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

unsigned int	ft_bits(char *tab)
{
	int						z;
	int						x;
	int						c;
	unsigned int			nbr;

	z = 0;
	x = (ft_strlen(tab) - 1);
	nbr = 0;
	c = 0;
	while (c <= x && tab[z] != '\0')
	{
		if (tab[z] == '#' || tab[z] == '1')
			nbr += ft_pow(2, c);
		c++;
		z++;
	}
	return (nbr);
}
