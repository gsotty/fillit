/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:54:42 by tapperce          #+#    #+#             */
/*   Updated: 2016/12/09 11:02:20 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

static unsigned int	ft_verif_3(unsigned int nbr)
{
	if (nbr == 17600 || nbr == 8800 || nbr == 4400 || nbr == 1100 ||
			nbr == 550 || nbr == 275)
		return (275);
	if (nbr == 36352 || nbr == 18176 || nbr == 2272 || nbr == 1136 ||
			nbr == 142 || nbr == 71)
		return (71);
	if (nbr == 51328 || nbr == 25664 || nbr == 12832 || nbr == 3208 ||
			nbr == 1604 || nbr == 802)
		return (802);
	if (nbr == 57856 || nbr == 28928 || nbr == 3616 || nbr == 1808 ||
			nbr == 226 || nbr == 113)
		return (113);
	return (0);
}

static unsigned int	ft_verif_2(unsigned int nbr)
{
	if (nbr == 19968 || nbr == 9984 || nbr == 1248 || nbr == 624 ||
			nbr == 78 || nbr == 39)
		return (39);
	if (nbr == 35968 || nbr == 9792 || nbr == 4896 || nbr == 2248 ||
			nbr == 1124 || nbr == 562)
		return (562);
	if (nbr == 58368 || nbr == 29184 || nbr == 3648 || nbr == 1824 ||
			nbr == 228 || nbr == 114)
		return (114);
	if (nbr == 19520 || nbr == 9760 || nbr == 4880 || nbr == 1220 ||
			nbr == 610 || nbr == 305)
		return (305);
	if (nbr == 35008 || nbr == 17504 || nbr == 8752 || nbr == 2188 ||
			nbr == 1094 || nbr == 547)
		return (547);
	if (nbr == 59392 || nbr == 29696 || nbr == 3712 || nbr == 1856 ||
			nbr == 232 || nbr == 116)
		return (116);
	if (nbr == 50240 || nbr == 25120 || nbr == 12560 || nbr == 3140 ||
			nbr == 1570 || nbr == 785)
		return (785);
	if (nbr == 11776 || nbr == 5888 || nbr == 736 || nbr == 368 ||
			nbr == 46 || nbr == 23)
		return (23);
	return (ft_verif_3(nbr));
}

unsigned int		ft_verif(unsigned int nbr)
{
	if (nbr == 61440 || nbr == 3840 || nbr == 240 || nbr == 15)
		return (15);
	if (nbr == 34952 || nbr == 17476 || nbr == 8738 || nbr == 4369)
		return (4369);
	if (nbr == 52224 || nbr == 26112 || nbr == 13056 || nbr == 3264 ||
			nbr == 1632 || nbr == 816 || nbr == 204 || nbr == 102 ||
			nbr == 51)
		return (51);
	if (nbr == 27648 || nbr == 13824 || nbr == 1728 || nbr == 864 ||
			nbr == 108 || nbr == 54)
		return (54);
	if (nbr == 35904 || nbr == 17952 || nbr == 8976 || nbr == 2244 ||
			nbr == 1122 || nbr == 561)
		return (561);
	if (nbr == 19584 || nbr == 5696 || nbr == 2848 || nbr == 1224 ||
			nbr == 612 || nbr == 306)
		return (306);
	if (nbr == 50688 || nbr == 25344 || nbr == 3168 || nbr == 1584 ||
			nbr == 198 || nbr == 99)
		return (99);
	return (ft_verif_2(nbr));
}
