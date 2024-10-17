/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numericlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:52:49 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/17 03:03:15 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"

size_t	ft_intlen(int num, t_flags f)
{
	size_t	len;

	len = 0;
	if (num < 0 || f.plus || f.space)
		len++;
	while (num)
	{
		num /= 10;
		len++;
	}
	if (f.width > len)
		return (f.width);
	return (len);
}

size_t	ft_uintlen(unsigned int num, t_flags f)
{
	size_t	len;

	len = 0;
	if (f.plus || f.space)
		len++;
	while (num)
	{
		num /= 10;
		len++;
	}
	if (f.width > len)
		return (f.width);
	return (len);
}

size_t	ft_octallen(unsigned int oct, t_flags f)
{
	size_t	len;

	len = 0;
	if (f.plus || f.space)
		len++;
	while (oct)
	{
		oct /= 8;
		len++;
	}
	if (f.width > len)
		return (f.width);
	return (len);
}

size_t	ft_hexlen(unsigned long hex, t_flags f)
{
	size_t	len;

	len = 0;
	if (f.plus || f.space)
		len++;
	while (hex)
	{
		hex /= 16;
		len++;
	}
	if (f.width > len)
		return (f.width);
	return (len);
}
