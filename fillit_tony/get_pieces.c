/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:15:49 by tapperce          #+#    #+#             */
/*   Updated: 2017/01/11 14:03:30 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_syntax(char *buf)
{
	int		i;
	int		diese;
	int		in_l;

	i = -1;
	diese = 0;
	while (buf[++i])
	{
		if ((i + 1) % 5 == 1)
			in_l = 0;
		if (buf[i] == '#' && in_l != -1)
		{
			diese++;
			in_l++;
		}
		if (in_l > 0 && buf[i] == '.')
			in_l = -1;
		if ((buf[i] != '.' && buf[i] != '#' && buf[i] != '\n') ||
				((i + 1) % 5 == 0 && buf[i] != '\n') || ((i + 1) % 5 != 0 &&
				buf[i] == '\n') || (buf[i] == '#' && in_l == -1))
			ft_exit(1, "error");
	}
	if (diese != 4)
		ft_exit(1, "error");
	return (1);
}

int		***get_pieces(int fd, int ***pieces)
{
	int		i;
	int		ret;
	int		tmp_ret;
	char	*buf;

	i = 0;
	if (!(buf = ft_strnew(BUF_SIZE)))
		ft_exit(1, "error");
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret <= 0)
			ft_exit(1, "error");
		if ((buf[BUF_SIZE - 1] != '\n') && (BUF_SIZE == ret))
			ft_exit(1, "error");
		buf[ret - 1] = '\0';
		if (check_syntax(buf) == 0)
			ft_exit(1, "error");
		store_piece(buf, pieces[i]);
		check_exist_0(pieces[i]);
		tmp_ret = ret;
		i++;
	}
	if ((tmp_ret == BUF_SIZE) || (ret == 0 && i == 0))
		ft_exit(1, "error");
	return (pieces);
}
