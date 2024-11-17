/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:29:22 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/17 15:08:35 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_str(char *str, t_flags *f)
{
	int	ret;
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
		len++;
	ret = 0;
	if (f->dot == true && len > f->width)
		len = f->width;
	else if (f->zero == true && f->hyphen == false && !(f->width) && !(f->dot))
		ret += ft_print_flag(' ', f->width - len);
	else if (f->width != 0 && f->hyphen == false && f->dot == false)
		ret += ft_print_flag(' ', f->width - len);
	ret += write(1, str, len);
	if (f->hyphen == true && f->width && f->dot == false)
		ret += ft_print_flag(' ', f->width - len);
	return (ret);
}
