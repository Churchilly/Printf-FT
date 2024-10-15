/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:19:54 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/15 18:32:47 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_flags
{
	bool	hyphen;
	bool	zero;
	bool	dot;
	bool	hash;
	bool	space;
	bool	plus;
	size_t	width;
}	t_flags;

typedef struct s_print_data
{
	char	*print;
	size_t	len;
}	t_print_data;

int		ft_printf(const char *format, ...);
bool	ft_get_printlen(const char *format, va_list args, s_print_data *p);
bool	ft_get_flags(const char *format, t_flags *f);
//add ft_create print
//add ft_handlers
//add ft_print

# endif