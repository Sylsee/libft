/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:00:49 by spoliart          #+#    #+#             */
/*   Updated: 2021/03/20 17:32:48 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free_all(char **ret, size_t i)
{
	while (--i + 1)
		free(ret[i]);
	free(ret);
	return (0);
}

static size_t	ft_wordlen(char const *s, char c, size_t i)
{
	size_t count;

	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static size_t	ft_nb_word(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	if (s[0] && s[0] != c)
		count++;
	while (s[i])
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char		*ft_fill_tab(char const *s, char c, char *ret, size_t *i)
{
	size_t j;

	j = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	while (s[*i] && s[*i] != c)
	{
		ret[j] = s[*i];
		(*i)++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char			**ft_split(char const *s, char c)
{
	int k;
	char			**ret;
	size_t			i;
	size_t			nb_word;
	size_t	j;

	i = 0;
	j = 0;
	nb_word = ft_nb_word(s, c);
	ret = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!ret)
		return (NULL);
	while (nb_word--)
	{
		ret[j] = (char *)malloc(sizeof(char) * ((k = ft_wordlen(s, c, i)) + 1));
		if (!ret[j])
			return (ft_free_all(ret, j));
		ret[j] = ft_fill_tab(s, c, ret[j], &i);
		j++;
	}
	ret[j] = NULL;
	return (ret);
}
