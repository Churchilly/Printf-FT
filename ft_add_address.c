/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:35:15 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/24 20:53:44 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

size_t	ft_addresslen(unsigned long address)
{
	size_t	len;

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

bool	ft_add_address(unsigned long address, t_pdata *p)
{
	size_t	len;
	size_t	i;
	char	*stradrs;

	len = ft_addresslen(address);
	stradrs = malloc(sizeof(char) * len + 3);
	if (!stradrs)
		return (false);
	stradrs[0] = '0';
	stradrs[1] = 'x';
	i = len + 1;
	if (address == 0)
		stradrs[2] = '0';
	while (address)
	{
		stradrs[i--] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	stradrs[len + 2] = '\0';
	if (!ft_add_toprint(stradrs, p))
		return (false);
	p->len += len + 2;
	free(stradrs);
	return (true);
}
