/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:49:26 by jukerboe          #+#    #+#             */
/*   Updated: 2019/11/28 14:43:21 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_print_percent(t_pf *pf)
{
	if (!pf->minus && !pf->zero)
		pf_putnchar(pf, ' ', pf->min_len - 1);
	else if (!pf->minus && pf->zero)
		pf_putnchar(pf, '0', pf->min_len - 1);
	pf_putchar(pf, '%');
	if (pf->minus)
		pf_putnchar(pf, ' ', pf->min_len - 1);
}

void	pf_print_char(t_pf *pf)
{
	int c;

	c = va_arg(pf->ap, int);
	if (!pf->minus)
		pf_putnchar(pf, ' ', (pf->min_len - 1));
	pf_putchar(pf, c);
	if (pf->minus)
		pf_putnchar(pf, ' ', (pf->min_len - 1));
}
