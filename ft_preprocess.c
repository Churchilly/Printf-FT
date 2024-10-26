/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:28:50 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/26 20:54:44 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_isspec(char f)
{
	return (f == 'c' || f == 's' || f == 'p'
		|| f == 'd' || f == 'i' || f == 'u'
		|| f == 'x' || f == 'X' || f == '%');
}

static bool	ft_handle_arg(const char spec, va_list args, t_pdata *p)
{
	bool	ret;

	ret = false;
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

bool	ft_preprocess(const char *format, va_list args, t_pdata *p)
{
	bool	is_added;

	is_added = false;
	while (*format)
	{
		if (!(is_added))
			if (!ft_add_toprint(format, p))
				return (false);
		is_added = true;
		if (*format == '%')
		{
			if (ft_isspec(*(++format)))
			{
				if (!(ft_handle_arg(*format, args, p)))
					return (false);
				p->len--;
				is_added = false;
			}
			else
				return (false);
		}
		format++;
		(p->len)++;
	}
	return (true);
}
