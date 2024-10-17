/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphalen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:41:45 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/18 01:00:30 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_charlen(t_flags f, t_pdata *p)
{
	if (f.width && !(f.dot))
		p->len += f.width;
	else
		p->len += 1;
}

bool	ft_strlen(char *arg, t_flags f, t_pdata *p)
{
	size_t	len;

	len = 0;
	while (arg[len])
		len++;
	if (f.plus && f.space)
		p->len += 1;
	if ((f.width && !(f.dot) && f.width > len))
		p->len += f.width;
	else
		p->len += len;
	return (true);
}
