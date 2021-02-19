/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:15:54 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/10 16:41:53 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old, size_t size)
{
	void *new;

	if (!(new = ft_memalloc(size)))
	{
		ft_memdel(&ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, old);
	ft_memdel(&ptr);
	return (new);
}
