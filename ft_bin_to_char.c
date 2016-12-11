/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:51:39 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/10 15:51:41 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include <stdlib.h>

char	*ft_bin_to_char(unsigned int n, int nbbits, int place)
{
	int				i;
	unsigned int	bit;
	unsigned int	mask;
	char			*buffer;

	i = 0;
	bit = 0;
	mask = 1;
	if (!(buffer = (char *)malloc(sizeof(char) * nbbits + 1)))
		return (NULL);
	while (i < nbbits)
	{
		bit = (n & mask) >> i;
		if (bit == 0)
			buffer[i] = '.';
		else if (bit == 1)
			buffer[i] = (char)('A' + place + bit);
		mask <<= 1;
		i++;
	}
	buffer[nbbits] = '\0';
	return (buffer);
}
