/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:35:21 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/05 18:48:37 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_area	g_ftarea;

/*
** area-based allocation built on malloc/free
*/

t_area	*init_area(t_area *area)
{
	if (area == NULL)
	{
		g_ftarea.freelist = NULL;
		return (&g_ftarea);
	}
	area->freelist = NULL;
	return (area);
}

/*
** Malloc a link and put it in area freelist
*/

void	*alloc(size_t size, t_area *area)
{
	t_link	*l;

	if (size > SIZE_MAX - sizeof(t_link))
		return (NULL);
	l = malloc(sizeof(t_link) + size);
	if (!l)
		return (NULL);
	l->next = area->freelist;
	l->prev = NULL;
	if (area->freelist)
		area->freelist->prev = l;
	area->freelist = l;
	return ((void *)(((char *)(l)) + sizeof(t_link)));
}

/*
** Free the link provided on the linked list (freelist) in area
*/

void	free_one(void *link, t_area *area)
{
	t_link	*l;

	if (!link)
		return ;
	l = (t_link *)(((char *)(link)) - sizeof(t_link));
	if (l->prev != NULL)
		l->prev->next = l->next;
	else
		area->freelist = l->next;
	if (l->next)
		l->next->prev = l->prev;
	free(l);
}

/*
** Free the linked list (freelist) in area
*/

void	free_area(t_area *area)
{
	t_link	*freelist;
	t_link	*tmp;

	if (area == NULL)
		freelist = g_ftarea.freelist;
	else
		freelist = area->freelist;
	while (freelist != NULL)
	{
		tmp = freelist->next;
		free(freelist);
		freelist = tmp;
	}
	if (area == NULL)
		g_ftarea.freelist = NULL;
	else
		area->freelist = NULL;
}
