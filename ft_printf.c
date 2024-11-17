/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:50:21 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/17 15:11:56 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static bool	ft_reset_flags(t_flags *f)
{
	f->err_hyphen = false;
	f->err_dot = false;
	f->hyphen = false;
	f->zero = false;
	f->dot = false;
	f->hash = false;
	f->space = false;
	f->plus = false;
	f->width = 0;
	return (1);
}

static int	ft_print_format(const char *format)
{
	const char	*p;

	p = format;
	while (*p != '%' && *p != '\0')
		p++;
	write(1, format, p - format);
	return (format - p);
}

static int	ft_print_arg(va_list args, char spec, t_flags *f)
{
	int	ret;

	if (f->err_hyphen == true)
		return (ft_reset_flags(f), write(1, "%.0-", 4));
	if (f->err_dot == true)
		return (ft_reset_flags(f), write(1, "%.0.", 4));
	ret = -1;
	if (spec == 'd' || spec == 'i')
		ret = ft_print_int(va_arg(args, int), f);
	else if (spec == 'u')
		ret = ft_print_uint(va_arg(args, unsigned int), f);
	else if (spec == 'x' || spec == 'X')
		ret = ft_print_hex(va_arg(args, unsigned int), spec, f);
	else if (spec == 'c')
		ret = ft_print_char(va_arg(args, int), f);
	else if (spec == 's')
		ret = ft_print_str(va_arg(args, char *), f);
	else if (spec == '%')
		ret = ft_print_char('%', f);
	else if (spec == 'p')
		ret = ft_print_address((unsigned long)va_arg(args, void *), f);
	return (ret);
}

static int	ft_process(const char *format, va_list args, t_flags *f)
{
	bool	is_added;
	int		len;
	int		ret;

	len = 0;
	is_added = 0;
	while (*format && ft_reset_flags(f))
	{
		if (!is_added)
			ret += ft_print_format(format);
		is_added = 1;
		if (*format == '%')
		{
			while (ft_get_flags(*(++format), f))
				;
			ret = ft_print_arg(args, *format, f);
			if (ret == -1)
				return (-1);
			len += ret - 1;
			is_added = 0;
		}
		len++;
		format++;
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
