/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:30:06 by dchernik          #+#    #+#             */
/*   Updated: 2024/10/30 18:52:14 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define STDOUT 1

int	ft_printf(char const *format, ...);

int	process_conv(char const *format, int spos, int epos);
int	next_sym_is_percent(char const *format, int *i);

/* args_cnt here is static variable declared in ft_printf.c ! */
int	char_conv(char const *format, int spos, int epos, int args_cnt);
int	string_conv(char const *format, int spos, int epos, int args_cnt);
int	ptr_conv(char const *format, int spos, int epos, int args_cnt);
int	nbr_conv(char const *format, int spos, int epos, int args_cnt);
int	u_nbr_conv(char const *format, int spos, int epos, int args_cnt);
int	hex_conv(char const *format, int spos, int epos, int args_cnt);

int	convs_count(char const *format);
int	is_conv(char ch);

#endif
