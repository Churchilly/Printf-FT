/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:28:50 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/11 22:36:54 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_arg(const char spec, va_list args, t_pdata *p)
{
	int	ret;

	if (!spec)
		return (ERROR);
	ret = STDERR;
	if (spec == 'd' || spec == 'i')
		ret = ft_add_int(va_arg(args, int), p);
	else if (spec == 'u')
		ret = ft_add_uint(va_arg(args, unsigned int), p);
	else if (spec == 'x' || spec == 'X')
		ret = ft_add_hex(va_arg(args, unsigned int), p, spec);
	else if (spec == 'c')
		ret = ft_add_char(va_arg(args, int), p);
	else if (spec == 's')
		ret = ft_add_str(va_arg(args, char *), p);
	else if (spec == '%')
		ret = ft_add_char('%', p);
	else if (spec == 'p')
		ret = ft_add_address((unsigned long)va_arg(args, void *), p);
	return (ret);
}

int	ft_preprocess(const char *format, va_list args, t_pdata *p)
{
	int	is_added;
	int	ret;

	is_added = 0;
	while (*format)
	{
		if (!(is_added))
			if (ft_add_toprint(format, p) == ERROR)
				return (ERROR);
		is_added = 1;
		if (*format == '%')
		{
			ret = ft_handle_arg(*(++format), args, p);
			if (ret == STDERR)
				return (STDERR);
			else if (ret == ERROR)
				return (ERROR);
			p->len--;
			is_added = 0;
		}
		format++;
		(p->len)++;
	}
	return (STDOUT);
}
