/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsurr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:47:46 by jukerboe          #+#    #+#             */
/*   Updated: 2020/04/27 14:48:11 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char	*ft_strsurr(char const *src, char add)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!(res = ft_strnew(ft_strlen(src) + 2)))
		return (NULL);
	res[0] = add;
	while (src[i])
	{
		res[j] = src[i];
		j++;
		i++;
	}
	res[j] = add;
	return (res);
}
