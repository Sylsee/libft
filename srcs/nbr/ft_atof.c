/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:29:25 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/19 03:01:27 by arguilla         ###   ########.fr       */
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
	if (nb == 0 && s[0] == '-')
		i++;
	if (s[i] == '.')
		i++;
	p = 1;
	while (ft_isdigit(s[i]) && p <= 100000000)
	{
		res = res * 10 + s[i++] - '0';
		p *= 10;
	}
	res /= p;
	if (nb == 0 && s[0] == '-')
		return ((nb + res) * -1);
	return (nb + res);
}
