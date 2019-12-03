/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:51:00 by jukerboe          #+#    #+#             */
/*   Updated: 2019/11/28 14:21:04 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putunbr(t_pf *pf, unsigned int nb)
{
	if (nb >= 10)
	{
		pf_putunbr(pf, nb / 10);
		pf_putchar(pf, nb % 10 + '0');
	}
	else
		pf_putchar(pf, nb + '0');
}

void	pf_putstr(t_pf *pf, char *s)
{
	write(1, s, ft_strlen(s));
	pf->ret += ft_strlen(s);
}

void	pf_putchar(t_pf *pf, char c)
{
	write(1, &c, 1);
	pf->ret += 1;
}

void	pf_putnchar(t_pf *pf, char c, int n)
{
	int		i;

	i = 0;
	if (n <= i)
		return ;
	while (i < n)
	{
		pf_putchar(pf, c);
		i++;
	}
}
