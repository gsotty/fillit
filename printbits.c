/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:22:47 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/09 11:04:10 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

#include <stdlib.h>

char	*ft_printbit(const unsigned int n, const int nbbits, int place)
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
