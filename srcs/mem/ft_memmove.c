/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:26:31 by spoliart          #+#    #+#             */
/*   Updated: 2020/10/27 21:37:35 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	tab[len];
	char	*pt_src;
	char	*pt_dst;

	i = 0;
	pt_src = (char *)src;
	pt_dst = (char *)dst;
	while (i < (int)len)
		tab[i++] = *pt_src++;
	i = 0;
	while (i < (int)len)
		*pt_dst++ = tab[i++];
	return (dst);
}
