/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_toprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:35:45 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/11 22:22:56 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_strend(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

static char	*ft_strnjoin(const char *str1, const char *str2,
							size_t len_str1, size_t size)
{
	char	*res;
	char	*ptr;

	res = malloc((len_str1 + size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ptr = res;
	while (str1 && *str1)
		*ptr++ = *str1++;
	while (size--)
		*ptr++ = *str2++;
	*ptr = '\0';
	return (res);
}

int	ft_add_toprint(const char *str, t_pdata *p)
{
	const char	*end_pos;
	size_t		len;
	char		*tmp;

	end_pos = ft_strend(str);
	len = end_pos - str;
	tmp = ft_strnjoin(p->toprint, str, p->len, len);
	if (!tmp)
		return (ERROR);
	if (p->toprint)
		free(p->toprint);
	p->toprint = tmp;
	return (STDOUT);
}
