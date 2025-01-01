/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:06:56 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/01 05:47:39 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_putchr(int c)
{
	return (write(1, &c, 1));
}

static int	ft_print_arg(char spec, va_list args)
{
	if (spec == 'd' || spec == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (spec == 'u')
		return (ft_print_uint(va_arg(args, unsigned int)));
	else if (spec == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (spec == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (spec == '%')
		return (write(1, &spec, 1));
	else if (spec == 'c')
		return (ft_putchr(va_arg(args, int)));
	else if (spec == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (spec == 'p')
		return (ft_print_address((unsigned long)va_arg(args, void *), 0));
	return (-1);
}

static int	ft_print_format(const char **format)
{
	const char	*p;

	p = *format;
	while (**format != '\0' && **format != '%')
	{
		(*format)++;
	}
	return (write(1, p, *format - p));
}

static int	ft_process(const char *format, va_list args)
{
	int	ret;
	int	tmp;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			tmp = ft_print_arg(*(++format), args);
			if (tmp == -1)
				return (ERROR);
			format++;
		}
		else
		{
			tmp = ft_print_format(&format);
			if (tmp == -1)
				return (ERROR);
		}
		ret += tmp;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	if (!format)
		return (ERROR);
	va_start(args, format);
	ret = ft_process(format, args);
	va_end(args);
	return (ret);
}
