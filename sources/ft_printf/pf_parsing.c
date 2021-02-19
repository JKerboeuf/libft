/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:26:02 by jukerboe          #+#    #+#             */
/*   Updated: 2019/11/28 15:05:41 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_flags(t_pf *pf, int *i, int *check)
{
	char	*str;

	str = ft_strchr("-0", pf->format[*i]);
	if (str)
	{
		if (*str == '-')
			pf->minus = 1;
		else if (*str == '0' && pf->format[*i - 1] != '.')
			pf->zero = 1;
	}
	if (pf->format[*i] == '.')
		*check = 1;
	if (pf->format[*i] > '0' && pf->format[*i] <= '9' && !pf->min_len)
	{
		while (ft_isdigit(pf->format[*i]) && !*check)
			pf->min_len = pf->min_len * 10 + pf->format[(*i)++] - '0';
		*check = 1;
	}
	if (pf->format[*i] == '*' && pf->format[(*i) - 1] != '.')
	{
		pf->min_len = va_arg(pf->ap, int);
		pf->minus = pf->min_len < 0 ? 1 : pf->minus;
		pf->min_len = pf->min_len < 0 ? -pf->min_len : pf->min_len;
	}
}

void	pf_prec(t_pf *pf, int *i, int *check)
{
	if (pf->format[*i] > '0' && pf->format[*i] <= '9')
	{
		pf->precision = 0;
		while (ft_isdigit(pf->format[*i]))
		{
			pf->precision = pf->precision * 10 + pf->format[*i] - '0';
			(*i)++;
		}
		(*i)--;
	}
	if (*check && !ft_isdigit(pf->format[*i]) && pf->format[(*i) - 1] == '.')
		pf->precision = 0;
	if (pf->format[*i] == '0' && pf->format[(*i) - 1] == '.')
		pf->precision = 0;
	if (pf->precision == -1 && pf->format[*i])
	{
		if (pf->format[*i] == '.' && pf->format[(*i) + 1] == '*')
		{
			pf->precision = va_arg(pf->ap, int);
			(*i)++;
			if (pf->precision < -1)
				pf->precision = -1;
		}
	}
}

void	pf_type(t_pf *pf, int *i)
{
	if (pf->format[*i] == 'c')
		pf->type = 'c';
	else if (pf->format[*i] == 's')
		pf->type = 's';
	else if (pf->format[*i] == 'd' || pf->format[*i] == 'i')
		pf->type = 'd';
	else if (pf->format[*i] == 'p')
		pf->type = 'p';
	else if (pf->format[*i] == 'u')
		pf->type = 'u';
	else if (pf->format[*i] == 'x')
		pf->type = 'x';
	else if (pf->format[*i] == 'X')
		pf->type = 'X';
	else if (pf->format[*i] == '%' && !pf->type)
		pf->type = '%';
	else if (pf->format[*i] == ' ')
		pf->space = 1;
}
