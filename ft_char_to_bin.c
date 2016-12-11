/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:29:17 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/10 12:29:58 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

unsigned int	ft_char_to_bin(char *tab)
{
	int				z;
	int				x;
	int				c;
	unsigned int	nbr;

	z = 0;
	c = 0;
	nbr = 0;
	x = (ft_strlen(tab) - 1);
	while (c <= x && tab[z] != '\0')
	{
		if (tab[z] == '#' || tab[z] == '1')
			nbr += ft_pow(2, c);
		c++;
		z++;
	}
	return (nbr);
}
