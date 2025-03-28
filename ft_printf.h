/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:30:06 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/28 04:13:55 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

# define STDOUT 1
# define LOWERCASE 1
# define UPPERCASE 2

/* args_cnt here is static variable declared in ft_printf.c ! */

/* ft_printf.c */
int		ft_printf(char const *format, ...);
int		next_sym_is_percent(char const *format, int *i);
int		process_conv(char const *format, va_list *vl, int cpos);
int		count_convs(char const *format);
int		is_conv(char ch);

/* non_numeric.c */
int		char_conv(va_list *vl);
int		string_conv(va_list *vl);
int		ptr_conv(va_list *vl);

/* numeric.c */
int		nbr_conv(va_list *vl);
int		u_nbr_conv(va_list *vl);
int		hex_conv(va_list *vl, int dcase);

/* utils.c */
char	*reverse_str(char *str);
char	*int_to_hex(unsigned long long num, int dcase);

#endif
