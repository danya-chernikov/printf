/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:30:06 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/27 20:33:44 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define STDOUT 1
# define LOWERCASE 1
# define UPPERCASE 2

/* args_cnt here is static variable declared in ft_printf.c ! */

/* ft_printf.c */
int		ft_printf(char const *format, ...);
int		next_sym_is_percent(char const *format, int *i);
int		process_conv(char const *format, void *arg, int spos, int epos);
int		count_convs(char const *format);
int		is_conv(char ch);

/* non_numeric.c */
int		char_conv(void *arg);
int		string_conv(void *arg);
int		ptr_conv(void *arg);

/* numeric.c */
int		nbr_conv(void *arg);
int		u_nbr_conv(void *arg);
int		hex_conv_upper(void *arg);
int		hex_conv_lower(void *arg);

/* utils.c */
char	*reverse_str(char *str);
char	*int_to_hex(unsigned int num, int dcase);

#endif
