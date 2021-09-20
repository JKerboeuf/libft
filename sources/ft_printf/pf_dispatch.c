/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:51:27 by jukerboe          #+#    #+#             */
/*   Updated: 2021/09/14 17:53:50 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf	*pf_dispatch(t_pf *pf)
{
	if (pf->type == '%')
		pf_print_percent(pf);
	else if (pf->type == 'c')
		pf_print_char(pf);
	else if (pf->type == 's')
		pf_print_str(pf);
	else if (pf->type == 'd' || pf->type == 'u')
		pf_check_nbr(pf);
	else if (pf->type == 'p')
		pf_print_ptr(pf);
	else if (pf->type == 'X' || pf->type == 'x')
	{
		if (pf->type == 'X')
			pf_check_hex(pf, 1);
		else
			pf_check_hex(pf, 0);
	}
	return (pf);
}
