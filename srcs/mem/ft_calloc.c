/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:00:10 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/26 20:48:56 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;

	count = count * size;
	pt = alloc(count, &g_ftarea);
	if (!pt)
		return (NULL);
	ft_bzero(pt, count);
	return (pt);
}
