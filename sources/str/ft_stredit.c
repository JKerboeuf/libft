/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stredit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:21:08 by jukerboe          #+#    #+#             */
/*   Updated: 2021/09/20 11:29:54 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	build_rest(char *res, char *src, size_t i, size_t end)
{
	size_t	k;

	k = end + 1;
	while (src[k])
	{
		res[i] = src[k];
		i++;
		k++;
	}
	res[i] = '\0';
}

static size_t	build_mod(char *res, char *mod, size_t i)
{
	size_t	j;

	j = 0;
	while (mod[j])
	{
		res[i] = mod[j];
		i++;
		j++;
	}
	return (i);
}

static size_t	build_src(char *res, char *src, size_t start)
{
	size_t	i;

	i = 0;
	while (i < start && src[i])
	{
		res[i] = src[i];
		i++;
	}
	return (i);
}

char	*ft_stredit(char *src, size_t start, size_t end, char *mod)
{
	char	*res;
	size_t	src_len;
	size_t	mod_len;
	size_t	new_len;
	size_t	i;

	if (src == NULL || mod == NULL || start > end)
		return (NULL);
	src_len = ft_strlen(src);
	mod_len = ft_strlen(mod);
	if (src_len == 0 || src_len < start || src_len < end)
		return (NULL);
	new_len = src_len - (end - start) + mod_len;
	res = (char *)malloc(sizeof(char) * new_len + 1);
	if (!res)
		return (NULL);
	i = build_src(res, src, start);
	i = build_mod(res, mod, i);
	build_rest(res, src, i, end);
	free(src);
	return (res);
}
