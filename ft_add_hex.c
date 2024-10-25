/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:16:54 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/24 20:53:29 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

size_t	ft_hexlen(unsigned int hex)
{
	size_t	len;

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

bool	ft_add_hex(unsigned int hex, t_pdata *p, const char spec)
{
	size_t	len;
	size_t	i;
	char	*strhex;
	char	*hexset;

	len = ft_hexlen(hex);
	strhex = malloc(sizeof(char) * len + 1);
	i = len - 1;
	if (spec == 'x')
		hexset = "0123456789abcdef";
	else
		hexset = "0123456789ABCDEF";
	if (hex == 0)
		strhex[0] = '0';
	while (hex)
	{
		strhex[i--] = hexset[hex % 16];
		hex /= 16;
	}
	strhex[len] = '\0';
	if (!ft_add_toprint(strhex, p))
		return (false);
	p->len += len;
	free(strhex);
	return (true);
}
