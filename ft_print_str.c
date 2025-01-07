/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:29:22 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/24 21:15:19 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_str(char *str, t_flags *f)
{
	int	ret;
	int	len;

	if ((f->dot && !f->lenght)
		|| (f->width < 6 && f->width && !str && f->lenght < 6 && f->lenght)
		|| (f->lenght < 6 && f->lenght && !str))
		str = "";
	if (!str)
		str = "(null)";
	len = 0;
	while (str && str[len])
		len++;
	ret = 0;
	if (f->dot && len > f->lenght)
		len = f->lenght;
	if (f->width && !f->hyphen && len < f->width)
		ret += ft_print_flag(' ', f->width - len);
	ret += write(1, str, len);
	if (f->hyphen && len < f->width)
		ret += ft_print_flag(' ', f->width - len);
	return (ret);
}
