/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:29:06 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/15 20:32:55 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_char(int c, t_flags *f)
{
	int	ret;

	ret = 0;
	if (f->zero == true && f->hyphen == false && f->width != 0 && !(f->dot))
		ret += ft_print_flag(' ', f->width - 1);
	else if (f->width != 0 && f->hyphen == false && f->dot == false)
		ret += ft_print_flag(' ', f->width - 1);
	ret += write(1, &c, 1);
	if (f->hyphen == true && f->width && f->dot == false)
		ret += ft_print_flag(' ', f->width - 1);
	return (ret);
}
