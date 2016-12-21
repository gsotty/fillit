/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:16:59 by tapperce          #+#    #+#             */
/*   Updated: 2016/12/21 16:58:29 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

char	**ft_store(int fd, char **pieces)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		i;

	i = 0;
	if (!(pieces = (char **)ft_memalloc(sizeof(char *) * 27)))
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		pieces[i] = (char *)NULL;
		if (!(pieces[i] = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
			return (NULL);
		buf[ret] = '\0';
		ft_strcpy(pieces[i], buf);
		if (ft_strlen(pieces[i]) != 20 || ft_strlen(pieces[i]) == 0)
			ft_exit(1, "error");
		ret = read(fd, buf, 1);
		buf[ret] = '\0';
		i++;
	}
	if (i == 0 || buf[0] == '\n')
		ft_exit(1, "error");
	close(fd);
	return (pieces);
}
