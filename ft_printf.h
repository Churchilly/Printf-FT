/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:07:03 by yusudemi          #+#    #+#             */
/*   Updated: 2025/01/01 05:05:52 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR -1

int	ft_printf(const char *format, ...);
int	ft_print_str(const char *str);
int	ft_print_int(int n);
int	ft_print_uint(int n);
int	ft_print_hex(unsigned int n, const char *hexset);
int	ft_print_address(unsigned long n, int prefixed);

#endif