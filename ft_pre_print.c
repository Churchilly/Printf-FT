/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:20:16 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/16 00:25:09 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdarg.h>
#include "ft_printf.h"

static bool	ft_is_specifier(const char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'o'
		|| c == 'x' || c == 'X' || c == 'f' || c == 'F'
		|| c == 'e' || c == 'E' || c == 'g' || c == 'G'
		|| c == 'a' || c == 'A' || c == 'c' || c == 's'
		|| c == 'p' || c == '%');
}

static bool	ft_is_valid_flag(const char c)
{
	return (c == '-' || c == '+' || c == ' '
		|| c == '0' || c == '#' || c == '.');
}

bool	ft_pre_print(const char *format, va_list args, t_pdata *p)
{
	while (*format)
	{
		if (*format == '%')
		{
			while (!ft_is_specifier(*++format))
			{
				if (!ft_is_valid_flag(*format))
					return (false);
				ft_get_flaglen(*format, &p);
			}
			if (ft_is_specifier(*format))
				ft_get_speclen(*format, args, &p);
			else
				return (false);
			format++;
		}
		else
		{
			p->len++;
			format++;
		}
	}
	return (true);
}
