/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:36:02 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/27 17:15:44 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_addresslen(unsigned long address)
{
	int	len;

	len = 0;
	if (address == 0)
		len++;
	while (address)
	{
		address /= 16;
		len++;
	}
	return (len);
}

static int	ft_putaddress(unsigned long address)
{
	char	c;

	if (address >= 16)
	{
		c = "0123456789abcdef"[address % 16];
		return (ft_putaddress(address / 16) + write(1, &c, 1));
	}
	return (c = "0123456789abcdef"[address], write(1, &c, 1));
}

static int	ft_handle_pre_flags(unsigned int address, t_flags *f,
								int address_len, int print_len)
{
	int	ret;

	ret = 0;
	if (f->width && !f->hyphen && !f->zero && address)
		ret += ft_print_flag(' ',
				(f->width - print_len - f->plus - f->space - 2));
	if (!f->hyphen && f->zero && address)
		ret += ft_print_flag(' ',
				(f->width - print_len - f->plus - f->space - 2));
	if (!address && f->width && !f->hyphen)
		ret += ft_print_flag(' ', f->width - address_len - f->plus - f->space);
	if (f->plus && address)
		ret += write(1, "+", 1);
	else if ((f->space && address)
		|| ((f->plus || f->space) && !address && f->width > f->lenght))
		ret += write(1, " ", 1);
	if (address)
		ret += write(1, "0x", 2);
	if (f->dot && f->lenght && address)
		ret += ft_print_flag('0', (f->lenght - address_len));
	if (f->zero && !f->hyphen && f->width && !f->dot && address)
		ret += ft_print_flag('0', (f->width - ret - address_len));
	return (ret);
}

int	ft_print_address(unsigned long address, t_flags *f)
{
	int	ret;
	int	address_len;
	int	print_len;

	address_len = ft_addresslen(address);
	if (!address)
		address_len = 5;
	print_len = address_len;
	if (f->lenght > print_len)
		print_len = f->lenght;
	ret = 0;
	ret += ft_handle_pre_flags(address, f, address_len, print_len);
	if (!address)
		ret += write(1, "(nil)", 5);
	else
		ret += ft_putaddress(address);
	if (f->hyphen && f->width)
		ret += ft_print_flag(' ', (f->width - ret));
	return (ret);
}
