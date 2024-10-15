/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:19:54 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/16 00:25:46 by yusudemi         ###   ########.fr       */
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

typedef struct s_pdata
{
	char	*print;
	size_t	len;
}	t_pdata;

int		ft_printf(const char *format, ...);
bool	ft_pre_print(const char *format, va_list args, t_flags *f, t_pdata *p);
bool	ft_get_speclen(const char specifier, va_list args, t_pdata *p);
void	ft_get_flaglen(const char flag, t_pdata *p);
bool	ft_print();
bool	ft_create_print();
bool	ft_print_print();
//add ft_create print
//add ft_handlers
//add ft_print

# endif