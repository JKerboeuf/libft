/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:11:54 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/10 16:42:54 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *stack, char const *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[i])
		return ((char*)stack);
	while (stack[i])
	{
		j = 0;
		while (needle[j] == stack[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)stack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
