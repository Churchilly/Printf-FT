/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:09:25 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/26 23:05:51 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static size_t	ft_strlen(char *str)
{
	char	*p;

	p = str;
	while (*p)
		p++;
	return (p - str);
}

static char	*ft_strjoin(char *str1, char *str2, size_t len1, size_t len2)
{
	size_t	i;
	char	*res;

	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	res[len1 + len2] = '\0';
	i = len1 + len2;
	while (len2 > 0)
		res[--i] = str2[--len2];
	while (len1 > 0)
		res[--i] = str1[--len1];
	return (res);
}

bool	ft_add_str(char *str, t_pdata *p)
{
	char	*tmp;

	if (!str)
	{
		tmp = ft_strjoin(p->toprint, "(null)", p->len, 6);
		p->len += 6;
	}
	else
	{
		tmp = ft_strjoin(p->toprint, str, p->len, ft_strlen(str));
		p->len += ft_strlen(str);
	}
	if (!tmp)
		return (false);
	if (p->toprint)
		free(p->toprint);
	p->toprint = tmp;
	return (true);
}
