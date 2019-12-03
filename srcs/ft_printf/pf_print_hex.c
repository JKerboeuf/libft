/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:49:40 by jukerboe          #+#    #+#             */
/*   Updated: 2019/11/28 14:27:54 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_check_hex(t_pf *pf, int up)
{
	char	str[15];
	int		len;

	len = pf_itohex(va_arg(pf->ap, unsigned int), str, up);
	pf_print_hex(pf, str, len);
}

int		pf_itohex(unsigned int nb, char *str, int up)
{
	char	*hex;
	int		i;
	int		j;

	i = 0;
	j = -1;
	hex = up ? (char[17]){"0123456789ABCDEF"} : (char[17]){"0123456789abcdef"};
	if (!nb)
	{
		str[0] = '0';
		str[1] = '\0';
		return (1);
	}
	while (nb > 0)
	{
		str[i++] = hex[nb % 16];
		nb /= 16;
	}
	str[i] = '\0';
	i--;
	while (j++ <= ((i / 2) - 1))
		ft_swap(&(str[j]), &(str[i - j]));
	return (i + 1);
}

void	pf_print_hex(t_pf *pf, char *str, int len)
{
	int	tmp_len;

	if (str[0] == '0' && pf->precision == 0)
	{
		str[0] = '\0';
		len--;
	}
	pf_print_hex2(pf, str, len, &tmp_len);
	if (pf->precision < 0 && pf->zero == 1 && pf->minus == 0)
	{
		pf_putnchar(pf, '0', (pf->min_len - len - pf->neg));
		pf_putstr(pf, str);
	}
	else if (pf->min_len >= pf->precision)
	{
		if (!pf->minus)
			pf_putnchar(pf, ' ', (tmp_len));
		pf_putnchar(pf, '0', (pf->precision - len));
		pf_putstr(pf, str);
		if (pf->minus)
			pf_putnchar(pf, ' ', (tmp_len));
	}
}

void	pf_print_hex2(t_pf *pf, char *str, int len, int *tmp_len)
{
	if (!pf->neg && pf->space)
		pf_putchar(pf, ' ');
	*tmp_len = 0;
	if (pf->min_len > pf->precision && pf->precision >= len)
		*tmp_len = pf->min_len - (pf->precision + pf->neg);
	else if (pf->precision >= pf->min_len && pf->precision >= len)
		*tmp_len = 0;
	else if (pf->min_len > pf->precision && len > pf->precision)
		*tmp_len = pf->min_len - len - pf->neg;
	if (pf->precision > pf->min_len)
	{
		pf_putnchar(pf, '0', (pf->precision - len));
		pf_putstr(pf, str);
	}
}
