/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:25:52 by jukerboe          #+#    #+#             */
/*   Updated: 2019/11/28 14:30:08 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_init(t_pf *pf, const char *format)
{
	pf->format = (char*)format;
	pf->ret = 0;
	pf_reset(pf);
	return (0);
}

void	pf_reset(t_pf *pf)
{
	pf->type = 0;
	pf->neg = 0;
	pf->min_len = 0;
	pf->precision = -1;
	pf->minus = 0;
	pf->zero = 0;
	pf->space = 0;
}

int		ft_printf(const char *format, ...)
{
	t_pf	pf;
	int		i;
	int		check;

	i = pf_init(&pf, format);
	va_start(pf.ap, format);
	while (pf.format[i] != '%' && pf.format[i])
		pf_putchar(&pf, pf.format[i++]);
	while (pf.format[i++])
	{
		check = 0;
		while (!pf.type && pf.format[i])
		{
			pf_flags(&pf, &i, &check);
			pf_prec(&pf, &i, &check);
			pf_type(&pf, &i);
			i++;
		}
		pf_reset(pf_dispatch(&pf));
		while (pf.format[i] != '%' && pf.format[i])
			pf_putchar(&pf, pf.format[i++]);
	}
	va_end(pf.ap);
	return (pf.ret);
}
