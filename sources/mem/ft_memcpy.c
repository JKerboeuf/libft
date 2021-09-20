/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:40:54 by jukerboe          #+#    #+#             */
/*   Updated: 2021/09/20 11:28:14 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char	*buff1;
	unsigned char	*buff2;

	if (!dst && !src)
		return (NULL);
	buff1 = (unsigned char *)((unsigned long)dst);
	buff2 = (unsigned char *)((unsigned long)src);
	while (n--)
		*buff1++ = *buff2++;
	return (dst);
}
