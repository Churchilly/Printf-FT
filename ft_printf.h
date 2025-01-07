/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:50:24 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/27 14:41:01 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdbool.h>

typedef struct s_flags
{
	bool			dot;
	bool			hash;
	bool			space;
	bool			plus;
	bool			hyphen;
	bool			zero;
	int				lenght;
	int				width;
}	t_flags;

int		ft_printf(const char *format, ...);
void	ft_get_flags(const char **flag, t_flags *f);
int		ft_print_flag(char flag, int len);
int		ft_print_char(int c, t_flags *f);
int		ft_print_percent(int c);
int		ft_print_str(char *str, t_flags *f);
int		ft_print_int(int num, t_flags *f);
int		ft_print_uint(unsigned int num, t_flags *f);
int		ft_print_hex(unsigned int hex, char spec, t_flags *f, char *hexset);
int		ft_print_address(unsigned long address, t_flags *f);

#endif