/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:29:17 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/19 11:42:34 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./libft/libft.h"

t_boardtype		ft_char_to_bin(char *tab)
{
	int				x;
	int				c;
	t_boardtype		nbr;

	c = 0;
	nbr = 0;
	x = (ft_strlen(tab) - 1);
	while (c <= x && tab[c] != '\0')
	{
		if (tab[c] == '#')
		{
			nbr += ft_pow(2, c);
			c++;
		}
		else if (tab[c] == '.')
		{
			c++;
		}
		else
			return (0);
	}
	return (nbr);
}
