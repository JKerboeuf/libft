/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:40:54 by jukerboe          #+#    #+#             */
/*   Updated: 2021/09/20 11:27:46 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	unsigned char	*buff1;
	unsigned char	*buff2;
	size_t			i;

	buff1 = (unsigned char *)dst;
	buff2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		buff1[i] = buff2[i];
		if (buff1[i] == (unsigned char)c)
			return ((void *)buff1 + i + 1);
		i++;
	}
	return (NULL);
}
