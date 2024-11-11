/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:30:45 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/11 16:56:19 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static size_t	ft_intlen(int num)
{
	size_t	len;

	len = 0;
	if (num <= 0)
	{
		len++;
		num = -num;
	}
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	ft_itostr(char *strnum, unsigned int num, size_t len)
{
	size_t	i;

	if (num == 0)
		strnum[0] = '0';
	i = len - 1;
	while (num)
	{
		strnum[i--] = "0123456789"[num % 10];
		num /= 10;
	}
	strnum[len] = '\0';
}

int	ft_add_int(int n, t_pdata *p)
{
	size_t			len;
	char			*strnum;
	unsigned int	num;

	len = ft_intlen(n);
	strnum = malloc((sizeof(char)) * len + 1);
	if (!strnum)
		return (ERROR);
	if (n < 0)
	{
		strnum[0] = '-';
		num = -n;
	}
	else
		num = n;
	ft_itostr(strnum, num, len);
	if (!strnum)
		return (ERROR);
	if (!ft_add_toprint(strnum, p))
		return (ERROR);
	p->len += len;
	free(strnum);
	return (STDOUT);
}
