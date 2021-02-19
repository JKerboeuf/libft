/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_tab_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:25:29 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/10 16:41:50 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_tab(char **s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		write(1, s[i], ft_strlen(s[i]));
		if (i != size - 1)
			write(1, "\n", 1);
		i++;
	}
}
