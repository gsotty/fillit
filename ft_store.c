/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:16:59 by tapperce          #+#    #+#             */
/*   Updated: 2016/12/19 11:43:31 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./libft/libft.h"
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
		buf[ret] = '\0';
		ft_strcpy(pieces[i], buf);
		if (ft_strlen(pieces[i]) != 20)
		{
			ft_putstr("error\n");
			return (NULL);
		}
		ret = read(fd, buf, 1);
		i++;
	}
	close(fd);
	return (pieces);
}
