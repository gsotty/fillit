/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:16:59 by tapperce          #+#    #+#             */
/*   Updated: 2016/12/10 12:43:51 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include <unistd.h>

char	**ft_store(int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	**pieces;
	int		ret;
	int		i;

	i = 0;
	if (!(pieces = ft_memalloc(sizeof(char*) * 27)))
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (!(pieces[i] = ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
			return (NULL);
		buf[ret - 1] = '\0';
		ft_strcpy(pieces[i], buf);
		i++;
	}
	close(fd);
	return (pieces);
}
