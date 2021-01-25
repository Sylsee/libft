/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:53:58 by spoliart          #+#    #+#             */
/*   Updated: 2020/11/01 17:18:30 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*pt;
	size_t	i;
	size_t	j;

	i = 0;
	pt = (char *)s1;
	if (!s2)
		return (pt);
	while (pt[i] && i < n)
	{
		j = 0;
		while (pt[i + j] == s2[j] && i + j < n)
			j++;
		if (!s2[j])
			return (&pt[i]);
		i++;
	}
	return (NULL);
}
