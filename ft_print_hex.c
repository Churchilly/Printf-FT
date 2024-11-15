/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:45:48 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/15 16:52:11 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_hexlen(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex == 0)
		len++;
	while (hex)
	{
		hex /= 16;
		len++;
	}
	return (len);
}

static int	ft_puthex(unsigned int hex, char *hexset)
{
	char	c;

	if (hex >= 16)
	{
		c = hexset[hex % 16];
		return (ft_puthex(hex / 16, hexset) + write(1, &c, 1));
	}
	c = hexset[hex];
	return (write(1, &c, 1));
}

int	ft_print_hex(unsigned int hex, char spec, t_flags *f)
{
	int		ret;
	int		hexlen;
	char	*hexset;

	hexlen = ft_hexlen(hex);
	ret = 0;
	if (f->dot == true && f->width != 0)
		ret += ft_print_flag('0', (f->width - hexlen));
	else if (f->zero == true && f->hyphen == false && f->width != 0)
		ret += ft_print_flag('0', (f->width - hexlen));
	else if (f->width != 0 && f->hyphen == false)
		ret += ft_print_flag(' ', (f->width - hexlen));
	if (f->hash == true)
		ret += write(1, "0x", 2);
	if (spec == 'x')
		hexset = "0123456789abcdef";
	else
		hexset = "0123456789ABCDEF";
	ret += ft_puthex(hex, hexset);
	if (f->hyphen == true && f->width && f->dot == false)
		ret += ft_print_flag(' ', (f->width - hexlen));
	return (ret);
}
