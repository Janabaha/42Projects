/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabukhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:02:53 by jabukhai          #+#    #+#             */
/*   Updated: 2026/10/19 18:03:11 by jabukhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**free_all(char **p, int i)
{
	while (i > 0)
	{
		free(p[--i]);
	}
	free(p);
	return (NULL);
}

static char	**substring(char const *s, char const *start, char **p, int i)
{
	p[i] = ft_substr(start, 0, s - start);
	if (!p[i])
		return (free_all(p, i));
	return (p);
}

static int	word_len(char const **s, char const **start, char c)
{
	while (**s == c)
		(*s)++;
	if (**s)
	{
		*start = *s;
		while (**s && **s != c)
			(*s)++;
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**p;
	const char	*start;
	int			i;

	if (!s)
		return (NULL);
	p = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	i = 0;
	while (word_len(&s, &start, c))
	{
		if (!substring(s, start, p, i))
			return (NULL);
		i++;
	}
	p[i] = NULL;
	return (p);
}
