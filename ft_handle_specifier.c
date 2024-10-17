/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:49:47 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/18 00:32:42 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdarg.h>
#include "ft_printf.h"

static bool	ft_hash(t_flags *f)
{
	f->hash = true;
	return (true);
}

static bool	ft_space(t_flags *f)
{
	if (f->plus != true)
		f->space = true;
	return (true);
}

static bool	ft_plus(t_flags *f)
{
	f->space = false;
	f->plus = true;
	return (true);
}

bool	ft_get_flags(const char flag, t_flags *f)
{
	if (flag == '0' && f->width == 0 && f->dot == false && f->hyphen == false)
		return (ft_zero(f));
	else if (flag == '.')
		return (ft_dot(f));
	else if (flag == '-' && f->dot == false)
		return (ft_hyphen(f));
	else if (flag == '#')
		return (ft_hash(f));
	else if (flag == ' ')
		return (ft_space(f));
	else if (flag == '+')
		return (ft_plus(f));
	else
		return (ft_width(flag, f));
}

bool	ft_get_speclen(const char spec, va_list args, t_flags *f, t_pdata *p)
{
	if (spec == 'd' || spec == 'i')
		ft_intlen(va_arg(args, int), *f, p);
	else if (spec == 'u')
		ft_uintlen(va_arg(args, unsigned int), *f, p);
	else if (spec == 'o')
		ft_octallen(va_arg(args, unsigned int), *f, p);
	else if (spec == 'x' || spec == 'X')
		ft_hexlen((unsigned long)va_arg(args, unsigned int), *f, p);
	else if (spec == 'c')
		ft_charlen(*f, p);
	else if (spec == 's')
		ft_strlen(va_arg(args, char *), *f, p);
	else if (spec == '%')
		p->len += 1;
	else if (spec == 'p')
		ft_hexlen((unsigned long)va_arg(args, void *), *f, p);
	else if (spec == 'f' || spec == 'F' || spec == 'g' || spec == 'G')
		ft_floatlen(va_arg(args, double), *f, p);
	else if (spec == 'e' || spec == 'E')
		ft_scilen(va_arg(args, double), *f, p);
	else if (spec == 'a' || spec == 'A')
		ft_hexfloatlen(va_arg(args, double), *f, p);
}
