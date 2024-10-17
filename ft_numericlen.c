/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numericlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:52:49 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/18 00:10:56 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"

bool	ft_intlen(int num, t_flags f, t_pdata *p)
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
		p->len += f.width;
	else
		p->len += len;
	return (true);
}

bool	ft_uintlen(unsigned int num, t_flags f, t_pdata *p)
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
		p->len += f.width;
	else
		p->len += len;
	return (true);
}

bool	ft_octallen(unsigned int oct, t_flags f, t_pdata *p)
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
	if (f.hash)
	{
		len++;
		f.width++;
	}
	if (f.width > len)
		p->len += f.width;
	else
		p->len += len;
	return (true);
}

bool	ft_hexlen(unsigned long hex, t_flags f, t_pdata *p)
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
	if (f.hash)
	{
		len += 2;
		f.width += 2;
	}
	if (f.width > len)
		p->len += f.width;
	else
		p->len += len;
	return (true);
}
