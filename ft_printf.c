/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:29 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/27 03:48:11 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <stdarg.h>
#include <unistd.h>

/* In a loop, we process all symbols in
 * the format string. If we find two
 * consecutive '%' symbols, we print
 * one of them. If the symbol following
 * '%' is not another '%', we continue
 * until we find a conversion symbol or
 * reach the end of the string. When we
 * find a conversion symbol corresponding
 * to that '%', we call process_conv(),
 * which will call the appropriate function
 * to handle the conversion. And finally
 * when we find a regular symbol we just
 * replicate it.
 *
 *     pbytes - number of bytes that were
 *              output by printf;
 *     spos   - starting position of a found
 *			    conversion field;
 *     i      - index variable. */
int	ft_printf(char const *format, ...)
{
	static int	pbytes = 0;
	int			i;
	int			spos;
	va_list		args;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			spos = i + 1;
			/* It means a single percent
			 * symbol is located at the
			 * end of the format string */
			if (format[i + 1] == '\0')
			{
				pbytes = -1;
				break;
			}
			if (next_sym_is_percent(format, &i))
				continue ;
			else
			{
				while (!is_conv(format[i]) && format[i] != '\0')
					i++;
				if (is_conv(format[i]))
					pbytes += process_conv(format, spos, i);
			}
		}
		else
		{
			ft_putchar_fd(format[i], STDOUT);
			pbytes++;
		}
		i++;
	}
	return (pbytes);
}

/* Determines if the symbol after the i position is
 * a percent symbol. If so, it prints '%' and skips
 * the i + 1 position. Returns 1 if the next symbol
 * after '%' is percent and 0 if not */
int	next_sym_is_percent(char const *format, int *i)
{
	if (format[*i + 1] == '%')
	{
		ft_putchar_fd('%', STDOUT);
		*i += 2;
		return (1);
	}
	return (0);
}

/* For each conversion calls the appropriate function
 * to handle it.
 *
 *     spos     - starting position of a found conversion
 *                field;
 *     epos     - ending position;
 *     args_cnt - the counter of the arguments that were
 *				  passed to ft_printf. we increment it
 *				  each time we find next '%'.
 *
 * In the string "just a number %-10.4d" spos is equal
 * to 15 and epos is equal to 19. */
int	process_conv(char const *format, int spos, int epos)
{
	static int	args_cnt = 1;
	int			pbytes;

	args_cnt++;
	if (format[epos] == 'c')
		pbytes = char_conv(format, spos, epos, args_cnt);
	if (format[epos] == 's')
		pbytes = string_conv(format, spos, epos, args_cnt);
	if (format[epos] == 'p')
		pbytes = ptr_conv(format, spos, epos, args_cnt);
	if (format[epos] == 'd' || format[epos] == 'i')
		pbytes = nbr_conv(format, spos, epos, args_cnt);
	if (format[epos] == 'u')
		pbytes = u_nbr_conv(format, spos, epos, args_cnt);
	if (format[epos] == 'x' || format[epos] == 'X')
		pbytes = hex_conv(format, spos, epos, args_cnt);
	return (pbytes);
}

/* Just to know how many items will
 * contain our array of pointers to
 * all conversions found in the
 * format string. */
int	convs_count(char const *format)
{
	int	cnv_num;
	int	i;

	cnv_num = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0' && format[i + 1] != '%')
			cnv_num++;
		i++;
	}
	return (cnv_num);
}

/* Determines if a symbol
 * belongs to a conversion
 * specifier symbols group */
int	is_conv(char ch)
{
	char const	*convs;
	int			i;

	convs = "cspdiuxX\0";
	i = 0;
	while (convs[i] != '\0')
	{
		if (ch == convs[i])
			return (1);
		i++;
	}
	return (0);
}
