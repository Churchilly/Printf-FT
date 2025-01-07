/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:50:35 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/27 17:33:27 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static bool	ft_is_flag(char flag)
{
	return (flag == '-' || (flag >= '0' && flag <= '9')
		|| flag == '#' || flag == ' ' || flag == '+');
}

bool	ft_is_spec(char spec)
{
	return (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x'
		|| spec == 'X' || spec == 'c' || spec == 's' || spec == '%'
		|| spec == 'p');
}

static void	ft_parse_flag(const char **flag, bool *f, int *value)
{
	if (f)
		*f = 1;
	if (**flag == '#' || **flag == ' ' || **flag == '+')
	{
		(*flag)++;
		return ;
	}
	if (**flag == '-' || **flag == '.' || **flag == '0')
		(*flag)++;
	while (**flag >= '0' && **flag <= '9')
	{
		*value = (*value * 10) + **flag - '0';
		(*flag)++;
	}
}

void	ft_get_flags(const char **flag, t_flags *f)
{
	(*flag)++;
	while (**(flag) && ft_is_flag(**flag))
	{
		f->width = 0;
		if (**flag == '#')
			ft_parse_flag(flag, &f->hash, NULL);
		if (**flag == ' ')
			ft_parse_flag(flag, &f->space, NULL);
		if (**flag == '+')
			ft_parse_flag(flag, &f->plus, NULL);
		if (**flag == '-')
			ft_parse_flag(flag, &f->hyphen, &f->width);
		if (**flag == '0')
			ft_parse_flag(flag, &f->zero, &f->width);
		if (**flag >= '0' && **flag <= '9')
			ft_parse_flag(flag, NULL, &f->width);
	}
	if (**flag == '.')
		ft_parse_flag(flag, &f->dot, &f->lenght);
}

int	ft_print_flag(char flag, int len)
{
	int	ret;

	if (len <= 0)
		return (0);
	ret = 0;
	while (len-- && ret != -1)
		ret += write(1, &flag, 1);
	return (ret);
}
