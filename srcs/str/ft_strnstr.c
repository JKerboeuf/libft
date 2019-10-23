/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:40:55 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/09 13:54:01 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *stack, char const *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[i])
		return ((char*)stack);
	while (stack[i] && i < len)
	{
		j = 0;
		while (needle[j] == stack[i + j] && (j + i) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char*)(stack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
