/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_tab_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:25:38 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/10 16:41:43 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_tab(int *n, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(n[i]);
		if (i != size - 1)
			write(1, " ", 1);
		i++;
	}
}
