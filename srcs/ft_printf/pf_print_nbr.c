/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:49:34 by jukerboe          #+#    #+#             */
/*   Updated: 2019/11/28 15:25:23 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_nb_len(unsigned int nb)
{
	int i;

	i = 0;
	if (!nb)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	pf_check_nbr(t_pf *pf)
{
	int				nb;
	int				nb_len;
	unsigned int	u_nb;

	nb_len = 0;
	nb = va_arg(pf->ap, int);
	u_nb = 0;
	if (nb < 0 && pf->type == 'd')
	{
		pf->neg = 1;
		if (nb == -2147483648)
		{
			u_nb = 2147483648;
			nb_len = pf_nb_len(u_nb);
			pf_print_nbr(pf, u_nb, nb_len);
			return ;
		}
		nb = -nb;
		nb_len = pf_nb_len(nb);
		pf_print_nbr(pf, nb, nb_len);
		return ;
	}
	nb_len = pf_nb_len((unsigned int)nb);
	pf_print_nbr(pf, (unsigned int)nb, nb_len);
}

void	pf_print_nbr(t_pf *pf, unsigned int nb, int nb_len)
{
	int	tmp_len;
	int	check;

	check = 1;
	if (!nb && !pf->precision)
		check = 0;
	if (!nb && !pf->precision)
		nb_len = 0;
	if (pf->neg && pf->precision > pf->min_len)
		pf_putchar(pf, '-');
	pf_print_nbr2(pf, nb, nb_len, &tmp_len);
	if (pf->precision < 0 && pf->zero && !pf->minus && check)
	{
		pf->neg ? pf_putchar(pf, '-') : write(1, "", 0);
		pf_putnchar(pf, '0', (pf->min_len - nb_len - pf->neg));
		pf_putunbr(pf, nb);
	}
	else if (pf->min_len >= pf->precision)
	{
		pf_print_nbr3(pf, tmp_len, check, nb_len);
		if (check)
			pf_putunbr(pf, nb);
		if (pf->minus)
			pf_putnchar(pf, ' ', (tmp_len));
	}
}

void	pf_print_nbr2(t_pf *pf, unsigned int nb, int nblen, int *tmp_len)
{
	int	check;

	check = 1;
	if (!nb && !pf->precision)
	{
		check = 0;
		nblen = 0;
	}
	if (!pf->neg && pf->space)
		pf_putchar(pf, ' ');
	*tmp_len = 0;
	if (pf->min_len > pf->precision && pf->precision >= nblen)
		*tmp_len = pf->min_len - (pf->precision + pf->neg);
	else if (pf->precision >= pf->min_len && pf->precision >= nblen)
		*tmp_len = 0;
	else if (pf->min_len > pf->precision && nblen > pf->precision)
		*tmp_len = pf->min_len - nblen - pf->neg;
	if (pf->precision > pf->min_len && check)
	{
		pf_putnchar(pf, '0', (pf->precision - nblen));
		pf_putunbr(pf, nb);
	}
}

void	pf_print_nbr3(t_pf *pf, int tmp_len, int check, int nb_len)
{
	if (!pf->minus)
		pf_putnchar(pf, ' ', (tmp_len));
	if (pf->neg)
		pf_putchar(pf, '-');
	if (check)
		pf_putnchar(pf, '0', (pf->precision - nb_len));
}
