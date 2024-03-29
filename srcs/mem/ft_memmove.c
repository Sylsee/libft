/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:26:31 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/05 18:46:51 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tab;
	unsigned char	*pt_src;
	unsigned char	*pt_dst;

	i = 0;
	pt_src = (unsigned char *)src;
	pt_dst = (unsigned char *)dst;
	tab = alloc(sizeof(unsigned char) * len, &g_ftarea);
	if (!tab)
		return (dst);
	if (!len || src == dst)
	{
		free_one(tab, &g_ftarea);
		return (dst);
	}
	while (i < len)
		tab[i++] = *pt_src++;
	i = 0;
	while (i < len)
		*pt_dst++ = tab[i++];
	free_one(tab, &g_ftarea);
	return (dst);
}
