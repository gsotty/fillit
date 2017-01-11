/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:15:49 by tapperce          #+#    #+#             */
/*   Updated: 2017/01/11 07:57:41 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**check_exist_3(int **pieces)
{
	if (pieces[0][0] == 0 && pieces[0][1] == 1 && pieces[1][0] == 0 &&
			pieces[1][1] == 3 && pieces[2][0] == 0 && pieces[2][1] == 0 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 2 && pieces[1][0] == 0 &&
			pieces[1][1] == 1 && pieces[2][0] == 0 && pieces[2][1] == 1 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 3 && pieces[1][0] == 2 &&
			pieces[1][1] == 1 && pieces[2][0] == 0 && pieces[2][1] == 0 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 1 && pieces[1][0] == 0 &&
			pieces[1][1] == 1 && pieces[2][0] == -1 && pieces[2][1] == 2 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 1 && pieces[1][0] == 0 &&
			pieces[1][1] == 1 && pieces[2][0] == 0 && pieces[2][1] == 2 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	return (0);
}

int		**check_exist_2(int **pieces)
{
	if (pieces[0][0] == 0 && pieces[0][1] == 1 && pieces[1][0] == 3 &&
			pieces[1][1] == 1 && pieces[2][0] == 0 && pieces[2][1] == 0 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 2 && pieces[1][0] == 1 &&
			pieces[1][1] == 1 && pieces[2][0] == 1 && pieces[2][1] == 1 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 1 && pieces[1][0] == -2 &&
			pieces[1][1] == 3 && pieces[2][0] == 0 && pieces[2][1] == 0 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 2 && pieces[1][0] == -1 &&
			pieces[1][1] == 2 && pieces[2][0] == 0 && pieces[2][1] == 0 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 1 && pieces[1][0] == 0 &&
			pieces[1][1] == 2 && pieces[2][0] == 1 && pieces[2][1] == 1 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	return (check_exist_3(pieces));
}

int		**check_exist_1(int **pieces)
{
	if (pieces[0][0] == 0 && pieces[0][1] == 1 && pieces[1][0] == -1 &&
			pieces[1][1] == 2 && pieces[2][0] == -1 && pieces[2][1] == -1 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 2 && pieces[1][0] == 1 &&
			pieces[1][1] == 2 && pieces[2][0] == 0 && pieces[2][1] == 0 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 1 && pieces[1][0] == -1 &&
			pieces[1][1] == 3 && pieces[2][0] == 0 && pieces[2][1] == 0 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 1 && pieces[1][0] == 0 &&
			pieces[1][1] == 2 && pieces[2][0] == 0 && pieces[2][1] == 1 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 1 && pieces[1][0] == -1 &&
			pieces[1][1] == 2 && pieces[2][0] == 0 && pieces[2][1] == 1 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	return (check_exist_2(pieces));
}

int		**check_exist_0(int **pieces)
{
	if (pieces[0][0] == 0 && pieces[0][1] == 3 && pieces[1][0] == 1 &&
			pieces[1][1] == 1 && pieces[2][0] == 0 && pieces[2][1] == 0 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 2 && pieces[1][0] == 0 &&
			pieces[1][1] == 2 && pieces[2][0] == 0 && pieces[2][1] == 0 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 4 && pieces[1][0] == 0 &&
			pieces[1][1] == 0 && pieces[2][0] == 0 && pieces[2][1] == 0 &&
			pieces[3][0] == 0 && pieces[3][1] == 0)
		return (pieces);
	if (pieces[0][0] == 0 && pieces[0][1] == 1 && pieces[1][0] == 0 &&
			pieces[1][1] == 1 && pieces[2][0] == 0 && pieces[2][1] == 1 &&
			pieces[3][0] == 0 && pieces[3][1] == 1)
		return (pieces);
	return (check_exist_1(pieces));
}

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
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n' &&
				(i + 1) % 5 == 0 && buf[i] != '\n' && (i + 1) % 5 != 0 &&
				buf[i] == '\n' && buf[i] == '#' && in_l == -1)
			return (0);
	}
	if (diese != 4)
		return (0);
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
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret < 0)
			return (0);
		if ((buf[BUF_SIZE - 1] != '\n') && (BUF_SIZE == ret))
			return (0);
		buf[ret - 1] = '\0';
		if (store_piece(buf, pieces[i]) == 0)
			return (0);
		tmp_ret = ret;
		i++;
	}
	if (tmp_ret == BUF_SIZE)
		return (0);
	return (pieces);
}
