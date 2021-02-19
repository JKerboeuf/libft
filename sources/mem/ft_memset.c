/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:57:51 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/09 13:53:10 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buff;

	if (len == 0)
		return (b);
	buff = (unsigned char *)b;
	while (len)
	{
		*buff = (unsigned char)c;
		if (len)
			buff++;
		len--;
	}
	return (b);
}
