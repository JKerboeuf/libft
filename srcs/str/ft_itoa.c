/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:40:54 by jukerboe          #+#    #+#             */
/*   Updated: 2019/10/17 11:56:42 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n, int sign)
{
	int		size;

	size = 1;
	n *= sign;
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	if (sign == -1)
		return (size + 1);
	else
		return (size);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		size_nb;
	int		sign;

	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		sign = -1;
	size_nb = get_size(n, sign);
	if (!(res = (char*)malloc(sizeof(char) * (size_nb + 1))))
		return (NULL);
	res[size_nb] = '\0';
	n *= sign;
	while (size_nb--)
	{
		res[size_nb] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
