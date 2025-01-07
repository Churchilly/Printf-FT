/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:50:21 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/27 17:56:23 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

static bool	ft_reset_flags(t_flags *f)
{
	f->dot = false;
	f->hash = false;
	f->space = false;
	f->plus = false;
	f->hyphen = false;
	f->zero = false;
	f->lenght = 0;
	f->width = 0;
	return (1);
}

static int	ft_print_format(const char *format)
{
	const char	*p;

	p = format;
	while (*p != '%' && *p != '\0')
		p++;
	return (write(1, format, p - format));
}

static int	ft_print_arg(va_list args, const char *spec, t_flags *f)
{
	if (*spec == 'd' || *spec == 'i')
		return (ft_print_int(va_arg(args, int), f));
	else if (*spec == 'u')
		return (ft_print_uint(va_arg(args, unsigned int), f));
	else if (*spec == 'x')
		return (ft_print_hex(va_arg(args, unsigned int),
				*spec, f, "0123456789abcdef"));
	else if (*spec == 'X')
		return (ft_print_hex(va_arg(args, unsigned int),
				*spec, f, "0123456789ABCDEF"));
	else if (*spec == 'c')
		return (ft_print_char(va_arg(args, int), f));
	else if (*spec == 's')
		return (ft_print_str(va_arg(args, char *), f));
	else if (*spec == '%')
		return (ft_print_percent('%'));
	else if (*spec == 'p')
		return (ft_print_address((unsigned long)va_arg(args, void *), f));
	return (-1);
}

static int	ft_process(const char *format, va_list args, t_flags *f)
{
	int		len;
	int		ret;

	len = 0;
	while (*format && ft_reset_flags(f))
	{
		ret = 0;
		if (*format != '%')
		{
			ret += ft_print_format(format);
			format = format + ret;
		}
		else if (*format == '%')
		{
			ft_get_flags(&format, f);
			ret = ft_print_arg(args, format, f);
			if (ret == -1)
				return (-1);
			format++;
		}
		len += ret;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	t_flags	f;

	if (!format)
		return (-1);
	va_start(args, format);
	ret = ft_process(format, args, &f);
	va_end(args);
	return (ret);
}
