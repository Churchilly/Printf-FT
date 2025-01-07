/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:50:19 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/24 21:22:02 by yusudemi         ###   ########.fr       */
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

static int	ft_putunbr(unsigned int num)
{
	char	c;

	if (num >= 10)
	{
		c = (num % 10) + '0';
		return (ft_putunbr(num / 10) + write(1, &c, 1));
	}
	c = num + '0';
	return (write(1, &c, 1));
}

static int	ft_handle_pre_flags(t_flags *f, int print_len, int int_len)
{
	int	ret;

	ret = 0;
	if (f->width > print_len && !(f->zero || f->hyphen))
		ret += ft_print_flag(' ', (f->width - print_len));
	if (f->zero && f->width > print_len && f->dot)
		ret += ft_print_flag(' ', f->width - print_len);
	if (f->zero && f->width > print_len && !f->dot)
		ret += ft_print_flag('0', f->width - print_len);
	if (f->dot)
		ret += ft_print_flag('0', f->lenght - int_len);
	return (ret);
}

int	ft_print_uint(unsigned int num, t_flags *f)
{
	int	ret;
	int	int_len;
	int	print_len;

	ret = 0;
	int_len = ft_uintlen(num);
	if (num == 0 && f->dot && !f->lenght && f->width)
		f->width++;
	print_len = int_len;
	if (f->dot && f->lenght > int_len)
		print_len = f->lenght;
	ret += ft_handle_pre_flags(f, print_len, int_len);
	if (!(num == 0 && f->dot && !f->lenght))
		ret += ft_putunbr(num);
	if (f->hyphen)
		ret += ft_print_flag(' ', (f->width - print_len));
	return (ret);
}
