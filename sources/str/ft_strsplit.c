/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:01:47 by jukerboe          #+#    #+#             */
/*   Updated: 2021/09/20 11:34:53 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**add_word(char **split, char *str)
{
	char	**new;
	int		n;

	n = 0;
	while (split[n])
		n++;
	new = ft_calloc(sizeof(char **), n + 2);
	if (!new)
		return (NULL);
	n = 0;
	while (split[n])
	{
		new[n] = split[n];
		n++;
	}
	free(split);
	new[n] = str;
	new[n + 1] = NULL;
	return (new);
}

static char	*get_word(const char *s, size_t *i, char c)
{
	char	*res;
	size_t	n;

	n = 0;
	while (s[*i + n] && s[*i + n] != c)
		n++;
	res = ft_calloc(sizeof(char), n + 1);
	if (!res)
		return (NULL);
	n = 0;
	while (s[*i + n] && s[*i + n] != c)
	{
		res[n] = s[*i + n];
		n++;
	}
	res[n] = '\0';
	*i = *i + n;
	return (res);
}

char	**ft_strsplit(char const *s, char c)
{
	char		**res;
	char		*word;
	size_t		i;

	res = ft_calloc(sizeof(char **), 1);
	if (!s || !res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word = get_word(s, &i, c);
			if (!word)
				return (free_all(res));
			res = add_word(res, word);
		}
	}
	return (res);
}
