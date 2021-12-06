/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:51:31 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/06 18:51:41 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str3join(const char *s1, const char *s2, const char *s3)
{
	size_t	i;
	size_t	j;
	char	*ret;

	ret = alloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1), NULL);
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		ret[i++] = s1[j];
	j = -1;
	while (s2[++j])
		ret[i++] = s2[j];
	j = -1;
	while (s3[++j])
		ret[i++] = s3[j];
	ret[i] = '\0';
	return (ret);
}
