/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:43:02 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/10 12:43:04 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

char	**ft_bin_pieces(char **pieces)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (pieces[i])
	{
		j = 0;
		k = 0;
		while (pieces[i][k])
		{
			pieces[i][j] = pieces[i][k];
			j++;
			k++;
			if (pieces[i][k] == '\n')
				k++;
		}
		pieces[i][j] = '\0';
		i++;
	}
	return (pieces);
}
