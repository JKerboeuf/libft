/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:59:04 by jukerboe          #+#    #+#             */
/*   Updated: 2021/09/20 11:33:13 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	char	*tmp;

	tmp = dst;
	while (len && *src)
	{
		*tmp++ = *src++;
		len--;
	}
	if (!*src)
		while (len-- && *tmp)
			*tmp++ = '\0';
	return (dst);
}
