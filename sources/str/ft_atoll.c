/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:56:17 by jukerboe          #+#    #+#             */
/*   Updated: 2021/09/20 15:03:53 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(char const *str)
{
	long long	res;
	int			neg;
	size_t		i;

	res = 0;
	neg = 0;
	i = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == '\f' || str[i] == ' '
			|| str[i] == '\v' || str[i] == '\r') && str[i] != '\0')
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
