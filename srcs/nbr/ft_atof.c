/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:29:25 by spoliart          #+#    #+#             */
/*   Updated: 2021/03/21 16:13:30 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atof(char *s)
{
	int		i;
	int		p;
	int		nb;
	float	result;

	nb = ft_atoi(s);
	i = ft_nbrlen(s);
	if (s[i] == '.')
		i++;
	p = 1;
	while (ft_isdigit(s[i]))
	{
		f = f * 10 + s[i++] - '0';
		p *= 10;
	}
	f /= p;
	return (nb + f);
}
