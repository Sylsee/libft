/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:07:06 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/26 07:24:53 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_xtoi(const char *hexstring)
{
	int		i;
	int		res;
	char	c;

	i = 0;
	res = 0;
	if (hexstring[i] == '0'
		&& (hexstring[i + 1] == 'x' || hexstring[i + 1] == 'X'))
		i += 2;
	while (hexstring[i])
	{
		c = ft_toupper(hexstring[i++]);
		if (c < '0' || c > 'F' || (c > '9' && c < 'A'))
			break ;
		c -= '0';
		if (c > 9)
			c -= 7;
		res = (res << 4) + c;
	}
	return (res);
}
