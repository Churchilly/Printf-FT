/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:28:50 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/24 19:58:22 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_isspec(char f)
{
	return (f == 'c' || f == 's' || f == 'p'
		|| f == 'd' || f == 'i' || f == 'u'
		|| f == 'x' || f == 'X' || f == '%');
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
