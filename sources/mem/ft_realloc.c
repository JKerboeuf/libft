/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:15:54 by jukerboe          #+#    #+#             */
/*   Updated: 2021/09/20 11:26:44 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old, size_t size)
{
	void	*new;

	new = ft_memalloc(size);
	if (!new)
	{
		ft_memdel(&ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, old);
	ft_memdel(&ptr);
	return (new);
}
