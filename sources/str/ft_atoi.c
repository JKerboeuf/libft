/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:40:54 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/09 13:53:15 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	int		res;
	int		neg;
	size_t	i;

	res = 0;
	neg = 0;
	i = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == '\f' ||
		str[i] == ' ' || str[i] == '\v' || str[i] == '\r') && str[i] != '\0')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58 && str[i])
	{
		res *= 10;
		res += (int)str[i] - 48;
		i++;
	}
	if (neg)
		return (-res);
	else
		return (res);
}
