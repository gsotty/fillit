/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:57:07 by tapperce          #+#    #+#             */
/*   Updated: 2016/12/09 11:00:43 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

char	**bin_pieces(char **pieces)
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
