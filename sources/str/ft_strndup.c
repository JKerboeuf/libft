/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:04:07 by jukerboe          #+#    #+#             */
/*   Updated: 2021/09/20 11:38:00 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *src, size_t n)
{
	char	*cpy;

	cpy = (char *)malloc(sizeof(char) * (n + 1));
	if (!cpy)
		return (NULL);
	ft_strncpy(cpy, src, n);
	cpy[n] = '\0';
	return (cpy);
}
