/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_islower_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:52:24 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/10 16:42:12 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_islower(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_islower(str[i]))
			return (0);
		i++;
	}
	return (1);
}
