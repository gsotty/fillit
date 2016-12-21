/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:44:32 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/21 16:56:26 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./libft/libft.h"
#include <stdlib.h>

void	ft_exit(int err, char *msg)
{
	if (err == 0)
		exit(err);
	else if (err == 1)
		ft_putendl(msg);
	exit(err);
}
