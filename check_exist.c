/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 08:11:22 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/11 13:22:29 by gsotty           ###   ########.fr       */
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
	ft_exit(1, "error");
	return (0);
}

int		**check_exist_2(int **pieces)
{
	if (pieces[0][0] == 0 && pieces[0][1] == 3 && pieces[1][0] == 0 &&
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
			pieces[1][1] == 2 && pieces[2][0] == -1 && pieces[2][1] == 1 &&
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
