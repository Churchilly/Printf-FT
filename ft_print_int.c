/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:50:32 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/15 16:36:34 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

static int	ft_intlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
	{
		len++;
		num = -num;
	}
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static int	ft_putnbr(int num)
{
	char	c;

	if (num == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
		return (1 + ft_putnbr(num));
	}
	if (num >= 10)
	{
		c = (num % 10) + '0';
		return (ft_putnbr(num / 10) + write(1, &c, 1));
	}
	c = num + '0';
	return (write(1, &c, 1));
}

int	ft_print_int(int num, t_flags *f)
{
	int	ret;
	int	len;

	len = ft_intlen(num);
	ret = 0;
	if (f->dot == true && f->width != 0)
		ret += ft_print_flag('0', f->width - len);
	else if (f->zero == true && f->hyphen == false && f->width != 0)
		ret += ft_print_flag('0', f->width - len);
	else if (f->width != 0 && f->hyphen == false)
		ret += ft_print_flag(' ', f->width - len);
	if (f->plus == true && num >= 0)
		ret += ft_print_flag('+', 1);
	else if (f->space == true && num >= 0)
		ret += ft_print_flag(' ', 1);
	ret += ft_putnbr(num);
	if (f->hyphen == true && f->width && f->dot == false)
		ret += ft_print_flag(' ', f->width - len);
	return (ret);
}
