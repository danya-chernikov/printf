/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 04:34:51 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/28 12:06:40 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

# define STDOUT 1
# define LOWERCASE 1
# define UPPERCASE 2

/* ft_printf.c */
int		ft_printf(char const *format, ...);
void	parse_format_str(char const *format, va_list *vl, int *pbytes);
int		process_percent(char const *format, va_list *vl, int *pbytes, int *i);
int		process_conv(char const *format, va_list *vl, int cpos);
int		next_sym_is_percent(char const *format, int *i);

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
int		is_conv(char ch);

/* ft_utils.c */
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

/* ft_itoa.c */
char	*ft_itoa(int n);

#endif
