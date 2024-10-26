/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:57:36 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/26 20:56:19 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

# define ERROR -1

typedef struct s_pdata
{
	char	*toprint;
	size_t	len;
}	t_pdata;

int		ft_printf(const char *format, ...);
bool	ft_preprocess(const char *format, va_list args, t_pdata *p);
bool	ft_add_toprint(const char *format, t_pdata *p);
bool	ft_add_int(int n, t_pdata *p);
bool	ft_add_uint(unsigned int n, t_pdata *p);
bool	ft_add_hex(unsigned int hex, t_pdata *p, const char spec);
bool	ft_add_char(int c, t_pdata *p);
bool	ft_add_str(char *str, t_pdata *p);
bool	ft_add_address(unsigned long address, t_pdata *p);

#endif