/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:41:02 by tapperce          #+#    #+#             */
/*   Updated: 2016/12/09 11:01:19 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "libft/libft.h"

int		char_to_bin(char *piece)
{
	int		result;
	int		size;
	int		i;

	size = ft_strlen(piece) - 1;
	i = 0;
	while (piece[i])
	{
		if (piece[i] == '#')
			result += ft_pow(2, size);
		i++;
		size--;
	}
	return (result);
}
