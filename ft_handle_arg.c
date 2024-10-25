/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:02:04 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/24 20:00:12 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_handle_arg(const char spec, va_list args, t_pdata *p)
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
