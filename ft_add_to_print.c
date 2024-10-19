/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:35:45 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/20 02:25:27 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"

static char	*ft_strpercnt(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return (char *)s;
		s++;
	}
	return ((char *)s);
}

static char	*ft_strnjoin(const char *str1, const char *str2, size_t n)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	res = malloc((len1 + len2 + 1) * sizeof(char));
	if (!res)
		return (false);
	while (*str1)
		*res++ = *str1++;
	while (len2--)
		*res++ = *str2++;
	*res = '\0';
	//maybe need to free(str1);
	return (res);
}

bool	ft_add_to_print(const char *str, t_pdata *p)
{
	const char	*percent_pos;
	size_t		len;

	percent_pos = ft_strpercnt(str);
	len = percent_pos - str;
	p->print = ft_strnjoin(p->print, str, len);
	if (!p->print)
		return (false);
	return (true);
}