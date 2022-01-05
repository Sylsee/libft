/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:29:25 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/05 23:12:35 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *s)
{
	int		i;
	int		p;
	int		nb;
	double	res;

	res = 0;
	nb = ft_atoi(s);
	i = ft_nbrlen(nb);
	if (s[i] == '.')
		i++;
	p = 1;
	while (ft_isdigit(s[i]) && p <= 100000000)
	{
		res = res * 10 + s[i++] - '0';
		p *= 10;
	}
	res /= p;
	return (nb + res);
}
