/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:09:25 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/04 06:50:41 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int	ft_pow(unsigned long long int a,
		unsigned long long int n)
{
	if (n == 0)
		return (1);
	else
		return (a * ft_pow(a, n - 1));
}
