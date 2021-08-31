/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:25:38 by jukerboe          #+#    #+#             */
/*   Updated: 2021/08/31 16:42:33 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include "libft.h"

typedef struct s_pf
{
	va_list		ap;
	char		*format;
	int			ret;
	char		type;
	int			neg;
	int			min_len;
	int			precision;
	int			minus;
	int			zero;
	int			space;
}				t_pf;

int				ft_printf(const char *format, ...);
int				pf_init(t_pf *pf, const char *format);
void			pf_reset(t_pf *pf);

t_pf			*pf_dispatch(t_pf *pf);
void			pf_flags(t_pf *pf, int *i, int *check);
void			pf_prec(t_pf *pf, int *i, int *check);
void			pf_type(t_pf *pf, int *i);

void			pf_check_hex(t_pf *pf, int up);
void			pf_print_hex(t_pf *pf, char *str, int len);
void			pf_print_hex2(t_pf *pf, char *str, int len, int *tmp_len);
int				pf_itohex(unsigned int nb, char *str, int up);
void			pf_print_ptr(t_pf *pf);
int				pf_ltohex(long int nb, char *str);
void			pf_check_nbr(t_pf *pf);
void			pf_print_nbr(t_pf *pf, unsigned int nb, int nb_len);
void			pf_print_nbr2(t_pf *pf, unsigned int nb, int nl, int *tmp_len);
void			pf_print_nbr3(t_pf *pf, int tmp_len, int check, int nb_len);
int				pf_nb_len(unsigned int nb);
void			pf_print_char(t_pf *pf);
void			pf_print_percent(t_pf *pf);
void			pf_print_str(t_pf *pf);
void			pf_print_str2(t_pf *pf, char *str, int len, int prec);

void			pf_putunbr(t_pf *pf, unsigned int nb);
void			pf_putstr(t_pf *pf, char *s);
void			pf_putchar(t_pf *pf, char c);
void			pf_putnchar(t_pf *pf, char c, int n);

#endif
