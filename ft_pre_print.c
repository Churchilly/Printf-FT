/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:20:16 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/17 03:18:37 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdarg.h>
#include "ft_printf.h"

static void	ft_reset_flags(t_flags *f)
{
	f->hyphen = false;
	f->zero = false;
	f->dot = false;
	f->hash = false;
	f->space = false;
	f->plus = false;
	f->width = false;
}

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
		|| c == '0' || c == '#' || c == '.'
		|| c == '1' || c == '2' || c == '3'
		|| c == '4' || c == '5' || c == '6'
		|| c == '7' || c == '8' || c == '9');
}

bool	ft_pre_print(const char *format, va_list args, t_flags *f, t_pdata *p)
{
	while (*format)
	{
		if (*format == '%')
		{
			ft_reset_flags(&f);
			while (!ft_is_specifier(*++format))
			{
				if (!ft_is_valid_flag(*format))
					return (false);
				if (!ft_get_flags(*format, f, p))
					return (false);
			}
			if (ft_is_specifier(*format))
				ft_get_speclen(*format, args, f, p);
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
