/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 00:28:00 by spoliart          #+#    #+#             */
/*   Updated: 2020/11/15 23:43:24 by spoliart         ###   ########.fr       */
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
	if (s[0] && s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c && i > 0)
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
	size_t	i;
	size_t	j;
	size_t	nb_word;
	char	**ret;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	nb_word = ft_nb_word(s, c);
	ret = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!ret)
		return (NULL);
	while (nb_word--)
	{
		ret[j] = (char *)malloc(sizeof(char) * (ft_wordlen(s, c, i) + 1));
		if (!ret[j])
			return (ft_free_all(ret, j));
		ret[j] = ft_fill_tab(s, c, ret[j], &i);
		j++;
	}
	ret[j] = (char *)malloc(sizeof(char));
	if (!ret[j])
		return (ft_free_all(ret, j));
	ret[j][0] = '\0';
	return (ret);
}
/*
int				main(int argc, char **argv)
{
	int i;
	char **ret;

	(void)argc;
	i = -1;
	printf("yo");
	ret = ft_split((char const *)argv[1], argv[2][0]);
	while (ret[++i])
		printf("%s\n", ret[i]);
}
*/
