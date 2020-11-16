/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:20:31 by spoliart          #+#    #+#             */
/*   Updated: 2020/11/15 23:52:51 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char const c, char const *set)
{
	size_t i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*pt;

	i = 0;
	j = 0;
	len = strlen((char *)s1) - 1;
	if (!s1 || !set)
		return (0);
	while (ft_is_charset(s1[i], set) && s1[i])
		i++;
	while (ft_is_charset(s1[len], set))
		len--;
	pt = (char *)malloc(sizeof(char) * (len - i + 2));
	if (!pt)
		return (0);
	while (i <= len)
		pt[j++] = s1[i++];
	pt[j] = '\0';
	return (pt);
}
