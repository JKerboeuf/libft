/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:40:54 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/09 13:52:59 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char	*buff1;
	unsigned char	*buff2;

	if (n == 0 || s1 == s2)
		return (0);
	buff1 = (unsigned char*)s1;
	buff2 = (unsigned char*)s2;
	while (n)
	{
		if (*buff1 != *buff2)
			return (*buff1 - *buff2);
		buff1++;
		buff2++;
		n--;
	}
	return (0);
}
