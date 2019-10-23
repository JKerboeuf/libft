/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:40:54 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/23 11:26:15 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	size_t	i;
	char	*res;

	if (!(s2 && s1))
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	i = 0;
	if (!(res = malloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	while (i < size1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		res[i] = s2[i - size1];
		i++;
	}
	res[size1 + size2] = '\0';
	return (res);
}
