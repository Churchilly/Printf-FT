/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:50:32 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/07 10:45:27 by yusudemi         ###   ########.fr       */
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
		len++;
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
		return (write(1, "2147483648", 11));
	if (num < 0)
	{
		num = -num;
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

static int	handle_pre_flags(int num, t_flags *f, int print_len, int int_len)
{
	int	ret;

	ret = 0;
	if (f->width > print_len && !(f->zero || f->hyphen))
		ret += ft_print_flag(' ', (f->width - print_len));
	if (f->zero && f->width > print_len && f->dot)
		ret += ft_print_flag(' ', f->width - print_len);
	if (num < 0)
		write(1, "-", 1);
	if (f->plus == true && num >= 0)
		ret += ft_print_flag('+', 1);
	else if (f->space == true && num >= 0)
		ret += ft_print_flag(' ', 1);
	if (f->zero && f->width > print_len && !f->dot)
		ret += ft_print_flag('0', f->width - print_len);
	if (f->dot && f->lenght > int_len)
		ret += ft_print_flag('0', f->lenght - int_len);
	return (ret);
}

int	ft_print_int(int num, t_flags *f)
{
	int	ret;
	int	int_len;
	int	print_len;

	ret = 0;
	int_len = ft_intlen(num);
	if (num < 0 && f->dot && f->lenght)
		f->lenght++;
	if ((num < 0 && f->width) || (num == 0 && f->dot && !f->lenght && f->width))
		f->width++;
	if (((f->plus && num >= 0) || (f->space && num >= 0)) && f->width)
		f->width--;
	print_len = int_len;
	if (f->dot && f->lenght > int_len)
		print_len = f->lenght;
	if ((f->width > print_len || f->hyphen > print_len) && num < 0)
		print_len++;
	ret += handle_pre_flags(num, f, print_len, int_len);
	if (!(num == 0 && f->dot && !f->lenght))
		ret += ft_putnbr(num);
	if (f->hyphen && f->width > print_len)
		ret += ft_print_flag(' ', (f->width - print_len));
	return (ret);
}
