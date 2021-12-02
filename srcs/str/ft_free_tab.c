/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 00:51:44 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/17 22:56:31 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab, t_area *area)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			free_one(tab[i], area);
		free_one(tab, area);
	}
	tab = NULL;
}
