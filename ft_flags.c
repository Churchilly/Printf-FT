/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:50:35 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/15 12:05:53 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

bool	ft_get_flags(char flag, t_flags *f)
{
	if (flag == '.')
		return (f->dot = true, true);
	else if (flag == '#')
		return (f->hash = true, true);
	else if (flag == '0' && f->width == 0)
		return (f->zero = true, true);
	else if (flag == '-')
		return (f->hyphen = true, true);
	else if (flag == ' ')
		return (f->space = true, true);
	else if (flag == '+')
		return (f->plus = true, true);
	else if (flag >= '0' && flag <= '9')
		return (f->width = (f->width * 10) + flag - '0', true);
	return (false);
}

int	ft_print_flag(char flag, int len)
{
	int	ret;

	if (len <= 0)
		return (0);
	ret = len;
	while (len--)
		write(1, &flag, 1);
	return (ret);
}
