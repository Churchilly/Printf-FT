/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:19:54 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/18 00:17:28 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_flags
{
	bool			hyphen;
	bool			zero;
	bool			dot;
	bool			hash;
	bool			space;
	bool			plus;
	unsigned int	width;
}	t_flags;

typedef struct s_pdata
{
	char	*print;
	size_t	len;
}	t_pdata;

int		ft_printf(const char *format, ...);
bool	ft_pre_process(const char *format, va_list args, t_flags *f, t_pdata *p);
bool	ft_get_flags(const char flag, t_flags *f);
bool	ft_zero(t_flags *f);
bool	ft_dot(t_flags *f);
bool	ft_hyphen(t_flags *f);
bool	ft_width(char flag, t_flags *f);
bool	ft_get_speclen(const char spec, va_list args, t_flags *f, t_pdata *p);
bool	ft_intlen(int num, t_flags f, t_pdata *p);
bool	ft_uintlen(unsigned int num, t_flags f, t_pdata *p);
bool	ft_octallen(unsigned int oct, t_flags f, t_pdata *p);
bool	ft_hexlen(unsigned long hex, t_flags f, t_pdata *p);



bool	ft_process();
bool	ft_create_print();
bool	ft_print_print();
//add ft_create print
//add ft_handlers
//add ft_print

# endif