/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:25:35 by spoliart          #+#    #+#             */
/*   Updated: 2020/11/02 00:52:08 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*pt_src;
	char		*pt_dst;

	pt_src = (char *)src;
	pt_dst = (char *)dst;
	while (n-- && *pt_src != c)
		*pt_dst++ = *pt_src++;
	if (*pt_src == c)
	{
		*pt_dst++ = *pt_src;
		return (pt_dst);
	}
	return (NULL);
}
