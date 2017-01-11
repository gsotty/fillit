/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:44:21 by tapperce          #+#    #+#             */
/*   Updated: 2017/01/10 17:09:50 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		test(int ***pieces)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(pieces[i][j][0]);
			ft_putstr(" / ");
			ft_putnbr(pieces[i][j][1]);
			ft_putchar('\n');
			j++;
		}
		i++;
	}
	return (1);
}
