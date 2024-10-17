/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:21:42 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/17 01:20:16 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <stdbool.h>

static void	ft_init_flags(t_flags *f)
{
	f->hyphen = false;
	f->zero = false;
	f->dot = false;
	f->hash = false;
	f->space = false;
	f->plus = false;
	f->width = false;
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_pdata			p;
	t_flags			f;

	if (!format || !(*format))
		return (NULL);
	va_start(args, format);
	ft_init_flags(&f);
	if (!ft_pre_print(format, args, &f, &p))
	{
		//printstr
		return (false);
	}
}
