/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:49:31 by jukerboe          #+#    #+#             */
/*   Updated: 2021/09/14 17:47:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_print_ptr(t_pf *pf)
{
	char	str[14];
	int		len;
	int		min_len;

	min_len = pf->min_len;
	len = (pf_ltohex(va_arg(pf->ap, long int), str) + 2);
	if (!pf->minus)
		pf_putnchar(pf, ' ', (min_len - len));
	pf_putstr(pf, "0x");
	pf_putstr(pf, str);
	if (pf->minus)
		pf_putnchar(pf, ' ', (min_len - len));
}

int	pf_ltohex(long int nb, char *str)
{
	char	*hex;
	int		i;
	int		j;

	i = 0;
	j = -1;
	hex = (char [17]){"0123456789abcdef"};
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
