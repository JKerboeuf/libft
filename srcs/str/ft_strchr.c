/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:40:54 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/09 13:53:25 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	size_t	i;

	i = 0;
	if (s[i] == c && !c)
		return ((char*)s);
	while (s[i])
	{
		if (s[i] == c)
			return ((char*)s + i);
		i++;
	}
	if (s[i] == c && !c)
		return ((char*)s + i);
	return (NULL);
}
