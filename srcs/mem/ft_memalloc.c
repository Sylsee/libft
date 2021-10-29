/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:24:08 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/26 20:49:15 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;

	ret = alloc(sizeof(void) * (size + 1), &g_ftarea);
	if (!ret)
		return (NULL);
	while (size--)
		*(char *)ret = 0;
	return (ret);
}
