/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_board_to_bin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:58:27 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/21 18:16:08 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./libft/libft.h"
#include <stdlib.h>

t_boardtype		*ft_conv_board_to_bin(char **tab)
{
	int				x;
	t_boardtype		*tab_int;

	x = 0;
	while (tab[x])
		x++;
	if (!(tab_int = (t_boardtype *)malloc(sizeof(t_boardtype) * x + 1)))
		ft_exit(1, "error");
	ft_bzero(tab_int, x + 1);
	x = 0;
	while (tab[x])
	{
		if ((tab_int[x] = ft_verif(ft_char_to_bin(tab[x]))) == 0)
			ft_exit(1, "error\n");
		x++;
	}
	tab[x] = 0;
	return (tab_int);
}
