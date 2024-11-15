/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:36:02 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/15 17:03:38 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_addresslen(unsigned int address)
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

static int	ft_putaddress(unsigned int address)
{
	char	c;

	if (address >= 16)
	{
		c = "0123456789abcdef"[address % 16];
		return (ft_putaddress(address / 16) + write(1, &c, 1));
	}
	return (c = "0123456789abcdef"[address], write(1, &c, 1));
}

int	ft_print_address(unsigned int address, t_flags *f)
{
	int	ret;
	int	address_len;

	if (!address)
		return (write(1, "(nil)", 5));
	address_len = ft_addresslen(address);
	ret = 0;
	if (f->width > 0 && !(f->hyphen) && !(f->dot) && !(f->zero))
		ret += ft_print_flag(' ', (f->width - address_len - 2));
	if (f->plus)
		ret += write(1, "+", 1);
	if (f->space)
		ret += write(1, " ", 1);
	ret += write(1, "0x", 2);
	if (f->dot == true && f->width != 0)
		ret += ft_print_flag('0', (f->width - address_len));
	else if (f->zero == true && f->hyphen == false && f->width != 0)
		ret += ft_print_flag('0', (f->width - address_len - 2));
	ret += ft_putaddress(address);
	if (f->hyphen == true && f->width && f->dot == false)
		ret += ft_print_flag(' ', (f->width - address_len - 2));
	return (ret);
}
