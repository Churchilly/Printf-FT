/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complexlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 01:00:18 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/20 02:05:44 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t ft_intlen(long n)
{
	size_t	len;
	
	len = 0;
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}


ft_floatlen(double arg, t_flags f, t_pdata *p)
{
	size_t	int_len;
	size_t	frac_len;
	long	int_part;
	double	frac_part;

	len = 0;
	int_part = (long)arg;
	frac_part = arg - int_part;
	if (arg < 0 || f.plus || f.space)
		len++;
	len += ft_intlen(int_part);
	

}

ft_scilen(double arg, t_flags f, t_pdata *p)
{
	
}

ft_hexfloatlen(double arg, t_flags f, t_pdata *p)
{
	
}