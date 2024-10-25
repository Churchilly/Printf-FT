/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:49:43 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/25 00:28:58 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static size_t	ft_uintlen(unsigned int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len++;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

bool	ft_add_uint(unsigned int n, t_pdata *p)
{
	size_t	len;
	size_t	i;
	char	*strnum;

	len = ft_uintlen(n);
	strnum = malloc((sizeof(char)) * len + 1);
	if (!strnum)
		return (false);
	if (n == 0)
		strnum[0] = '0';
	i = len - 1;
	while (n)
	{
		strnum[i--] = "0123456789"[n % 10];
		n = n / 10;
	}
	strnum[len] = '\0';
	if (!ft_add_toprint(strnum, p))
		return (false);
	p->len += len;
	free(strnum);
	return (true);
}
