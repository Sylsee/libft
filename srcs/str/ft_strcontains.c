/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 00:58:46 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/09 01:02:12 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcontains(const char *s, const char *set)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_charset(s[i], set) == 1)
			return (1);
		i++;
	}
	return (0);
}
