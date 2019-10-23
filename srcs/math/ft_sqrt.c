/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:50:39 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/10 16:41:56 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int	res;
	int	j;

	res = 2;
	if (nb < 0)
		return (0);
	else if (nb < 2)
		return (nb);
	j = nb;
	while (res <= j / 2)
	{
		if (res * res == nb)
			return (res);
		res++;
		j--;
	}
	return (0);
}
