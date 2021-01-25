/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:17:08 by spoliart          #+#    #+#             */
/*   Updated: 2020/11/15 23:50:56 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ret = (char *)malloc(sizeof(char) * (j + 1));
	if (!ret)
		return (NULL);
	j = -1;
	while (s1[++j])
	{
		ret[i] = s1[j];
		i++;
	}
	j = -1;
	while (s2[++j])
	{
		ret[i] = s2[j];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
