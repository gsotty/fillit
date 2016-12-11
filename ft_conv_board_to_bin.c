/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_board_to_bin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:58:27 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/10 13:01:20 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include <stdlib.h>

unsigned int		*ft_conv_board_to_bin(char **tab)
{
	int				x;
	unsigned int	*tab_int;

	x = 0;
	while (tab[x])
		x++;
	if (!(tab_int = (unsigned int *)malloc(sizeof(unsigned int) * x + 1)))
		return (NULL);
	ft_bzero(tab_int, x + 1);
	x = 0;
	while (tab[x])
	{
		if ((tab_int[x] = ft_verif(ft_char_to_bin(tab[x]))) == 0)
			return (NULL);
		x++;
	}
	tab[x] = 0;
	return (tab_int);
}
