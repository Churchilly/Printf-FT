/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:45:48 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/24 17:36:07 by yusudemi         ###   ########.fr       */
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

static int	ft_handle_pre_flags(t_flags *f, int print_len,
								int hex_len, char hash_spec)
{
	int	ret;

	ret = 0;
	if (f->width > print_len && !(f->zero || f->hyphen))
		ret += ft_print_flag(' ', (f->width - print_len));
	if (f->zero && f->width > print_len && f->dot)
		ret += ft_print_flag(' ', f->width - print_len);
	if (hash_spec == 'x' && f->hash)
		ret += write(1, "0x", 2);
	else if (hash_spec == 'X' && f->hash)
		ret += write(1, "0X", 2);
	if (f->zero && f->width > print_len && !f->dot)
		ret += ft_print_flag('0', f->width - print_len);
	if (f->dot)
		ret += ft_print_flag('0', f->lenght - hex_len);
	return (ret);
}

int	ft_print_hex(unsigned int hex, char spec, t_flags *f, char *hexset)
{
	int		ret;
	int		hexlen;
	int		print_len;

	ret = 0;
	hexlen = ft_hexlen(hex);
	if (hex == 0 && f->dot && !f->lenght && f->width)
		f->width++;
	print_len = hexlen;
	if (f->dot && f->lenght > hexlen)
		print_len = f->lenght;
	if (f->hash && hex != 0)
		print_len += 2;
	else if (f->hash && hex == 0)
		spec = 0;
	ret += ft_handle_pre_flags(f, print_len, hexlen, spec);
	if (!(hex == 0 && f->dot && !f->lenght))
		ret += ft_puthex(hex, hexset);
	if (f->hyphen)
		ret += ft_print_flag(' ', (f->width - print_len));
	return (ret);
}
