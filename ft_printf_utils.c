/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:38:51 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/01 05:34:49 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_str(const char *str)
{
	const char	*p;

	if (!str)
		return (ft_print_str("(null)"));
	p = str;
	while (*p)
		p++;
	return (write(1, str, p - str));
}

int	ft_print_int(int n)
{
	int	ret;
	int	tmp;

	ret = 0;
	tmp = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
		ret++;
	}
	if (n >= 10)
	{
		tmp = ft_print_int(n / 10);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (write(1, &("0123456789"[n % 10]), 1) == -1)
		return (-1);
	return (ret + 1);
}

int	ft_print_uint(unsigned int n)
{
	int	ret;
	int	tmp;

	ret = 0;
	tmp = 0;
	if (n >= 10)
	{
		tmp = ft_print_uint(n / 10);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (write(1, &("0123456789"[n % 10]), 1) == -1)
		return (-1);
	return (ret + 1);
}

int	ft_print_hex(unsigned int n, const char *hexset)
{
	int	ret;
	int	tmp;

	ret = 0;
	tmp = 0;
	if (n >= 16)
	{
		tmp = ft_print_hex(n / 16, hexset);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (write(1, &(hexset[n % 16]), 1) == -1)
		return (-1);
	return (ret + 1);
}

int	ft_print_address(unsigned long n, int prefixed)
{
	int			ret;
	int			tmp;
	const char	*hexset = "0123456789abcdef";

	if (!n)
		return (ft_print_str("(nil)"));
	ret = 0;
	tmp = 0;
	if (!prefixed)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		ret += 2;
	}
	if (n >= 16)
	{
		tmp = ft_print_address(n / 16, 1);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (write(1, &(hexset[n % 16]), 1) == -1)
		return (-1);
	return (ret + 1);
}
