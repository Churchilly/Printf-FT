/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:17:08 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/17 19:04:08 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_zero(t_flags *f)
{
	f->zero = true;
	return (true);
}

bool	ft_dot(t_flags *f)
{
	if (f->dot == true || f->hyphen == true || f->zero == true)
		return (false);
	f->dot = true;
	return (true);
}

bool	ft_hyphen(t_flags *f)
{
	if (f->dot == true || f->hyphen == true || f->zero == true)
		return (false);
	f->hyphen = true;
	return (true);
}

bool	ft_width(char flag, t_flags *f)
{
	f->width = f->width * 10 + (flag - '0');
	return (true);
}