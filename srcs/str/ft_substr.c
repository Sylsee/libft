/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:29:23 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/26 20:53:43 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*ret;

	i = 0;
	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) + 1)
		size = ft_strlen(s);
	else
		size = len;
	ret = alloc(sizeof(char) * (size + 1), &g_ftarea);
	if (!ret)
		return (NULL);
	while (s[start + i] && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
