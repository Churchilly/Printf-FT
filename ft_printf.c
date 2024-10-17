/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:21:42 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/18 00:14:21 by yusudemi         ###   ########.fr       */
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
	if (!ft_pre_process(format, args, &f, &p))
	{
		//printstr
		return (false);
	}
	//p->print = malloc(p->len * char);
	//ft_process(format, args, &p)
}
