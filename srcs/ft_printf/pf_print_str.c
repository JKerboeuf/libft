/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:49:29 by jukerboe          #+#    #+#             */
/*   Updated: 2019/11/28 15:06:33 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_print_str(t_pf *pf)
{
	int		len;
	char	*str;

	str = va_arg(pf->ap, char*);
	if (!str)
		str = (char[7]){"(null)"};
	len = ft_strlen(str);
	if (pf->precision >= len)
	{
		if (!pf->minus)
			pf_putnchar(pf, ' ', (pf->min_len - len));
		pf_putstr(pf, str);
		if (pf->minus)
			pf_putnchar(pf, ' ', (pf->min_len - len));
	}
	pf_print_str2(pf, str, len, pf->precision);
}

void	pf_print_str2(t_pf *pf, char *str, int len, int prec)
{
	if (pf->precision < len && prec == -1)
	{
		if ((pf->min_len > pf->precision) && !pf->minus)
			pf_putnchar(pf, ' ', (pf->min_len - (pf->precision + 1) - len));
		pf_putstr(pf, str);
		if ((pf->min_len > pf->precision) && pf->minus)
			pf_putnchar(pf, ' ', (pf->min_len - (pf->precision + 1) - len));
	}
	else if (pf->precision < len && pf->precision >= 0)
	{
		if ((pf->min_len > pf->precision) && !pf->minus)
			pf_putnchar(pf, ' ', (pf->min_len - pf->precision));
		while (prec-- > 0)
			pf_putchar(pf, *str++);
		if ((pf->min_len > pf->precision) && pf->minus)
			pf_putnchar(pf, ' ', (pf->min_len - pf->precision));
	}
}
