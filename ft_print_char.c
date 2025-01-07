/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:29:06 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/23 16:46:09 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_char(int c, t_flags *f)
{
	int	ret;

	ret = 0;
	if (f->width && !f->hyphen)
		ret += ft_print_flag(' ', f->width - 1);
	ret += write(1, &c, 1);
	if (f->hyphen && f->width)
		ret += ft_print_flag(' ', f->width - 1);
	return (ret);
}

int	ft_print_percent(int c)
{
	int	ret;

	ret = 0;
	ret += write(1, &c, 1);
	return (ret);
}
