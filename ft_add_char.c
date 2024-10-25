/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:53:01 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/25 02:16:02 by yusudemi         ###   ########.fr       */
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

static char	*ft_strchrjoin(char *str1, char c)
{
	size_t	len1;
	char	*res;
	char	*ptr;

	len1 = ft_strlen(str1);
	res = malloc(sizeof(char) * (len1 + 2));
	if (!res)
		return (NULL);
	ptr = res;
	while (*str1)
		*ptr++ = *str1++;
	*ptr++ = c;
	*ptr = '\0';
	return (res);
}

bool	ft_add_char(int c, t_pdata *p)
{
	char	*tmp;

	tmp = ft_strchrjoin(p->toprint, (char)c);
	if (!tmp)
		return (false);
	p->len += 1;
	if (p->toprint)
		free(p->toprint);
	p->toprint = tmp;
	return (true);
}
