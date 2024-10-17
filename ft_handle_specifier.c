/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:49:47 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/17 03:25:22 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdarg.h>
#include "ft_printf.h"

bool	ft_get_flags(const char flag, t_flags *f, t_pdata *p)
{
	if (flag == '0' && f->width == 0 && f->zero == false)
		return (ft_fzero());
	else if (flag == '.')
		return (ft_fdot());
	else if (flag == '-')
		return (ft_hyphen());
	else if (flag == '#')
		return (ft_hash());
	else if (flag == ' ')
		return (ft_space());
	else if (flag == '+')
		return (ft_plus());
	else
		return (ft_width());
}

void	ft_get_speclen(const char spec, va_list args, t_flags *f, t_pdata *p)
{
	if (spec == 'd' || spec == 'i')
		p->len += ft_intlen(va_arg(args, int), *f);
	else if (spec == 'u')
		p->len += ft_uintlen(va_arg(args, unsigned int), *f);
	else if (spec == 'o')
		p->len += ft_octallen(va_arg(args, unsigned int), *f);
	else if (spec == 'x' || spec == 'X')
		p->len += ft_hexlen((unsigned long)va_arg(args, unsigned int), *f);
	else if (spec == 'c' || spec == '%')
		p->len += ft_charlen(*f);
	else if (spec == 's')
		p->len += ft_strlen(va_arg(args, char *), *f);
	else if (spec == 'p')
		p->len += ft_hexlen((unsigned long)va_arg(args, void *), *f);
	else if (spec == 'f' || spec == 'F' || spec == 'g' || spec == 'G')
		p->len += ft_floatlen(va_arg(args, double), *f);
	else if (spec == 'e' || spec == 'E')
		p->len += ft_scilen(va_arg(args, double), *f);
	else if (spec == 'a' || spec == 'A')
		p->len += ft_hexfloatlen(va_arg(args, double), *f);
}
