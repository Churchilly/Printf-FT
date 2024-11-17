/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:50:19 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/15 17:55:58 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_uintlen(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static int	ft_putunbr(unsigned int unum)
{
	char	c;

	if (unum >= 10)
		return (c = unum % 10 + '0', ft_putunbr(unum / 10) + write(1, &c, 1));
	c = unum + '0';
	return (write(1, &c, 1));
}

int	ft_print_uint(unsigned int unum, t_flags *f)
{
	int	ret;
	int	len;

	len = ft_uintlen(unum);
	ret = 0;
	if (f->dot == true && f->width != 0)
		ret += ft_print_flag('0', f->width - len);
	else if (f->zero && !(f->hyphen) && f->width && !(f->dot))
		ret += ft_print_flag('0', f->width - len);
	else if (f->width != 0 && f->hyphen == false)
		ret += ft_print_flag(' ', f->width - len);
	ret += ft_putunbr(unum);
	if (f->hyphen == true && f->width && f->dot == false)
		ret += ft_print_flag(' ', f->width - len);
	return (ret);
}
