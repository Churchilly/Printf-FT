/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:22:32 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/11 17:36:06 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static void	ft_init_pdata(t_pdata *p)
{
	p->toprint = NULL;
	p->len = 0;
}

size_t	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p)
		p++;
	return (p - str);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_pdata	p;
	int		ret;

	if (!(format))
		return (ERROR);
	va_start(args, format);
	ft_init_pdata(&p);
	ret = ft_preprocess(format, args, &p);
	if (ret == ERROR)
		return (ERROR);
	else if (ret == STDERR)
	{
		if (p.toprint)
			free(p.toprint);
		return (write(STDERR, format, ft_strlen(format)));
	}
	write(1, p.toprint, p.len);
	va_end(args);
	free(p.toprint);
	return (p.len);
}
