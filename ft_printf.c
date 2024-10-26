/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:22:32 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/27 00:37:36 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	ft_init_pdata(t_pdata *p)
{
	p->toprint = NULL;
	p->len = 0;
}

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_pdata	p;

	if (!(format))
		return (ERROR);
	va_start(args, format);
	ft_init_pdata(&p);
	if (!(ft_preprocess(format, args, &p)))
	{
		write(1, format, ft_strlen(format));
		if (p.toprint)
			free(p.toprint);
		return (ERROR);
	}
	write(1, p.toprint, p.len);
	va_end(args);
	free(p.toprint);
	return (p.len);
}
