/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:29 by dchernik          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/27 03:48:11 by dchernik         ###   ########.fr       */
=======
/*   Updated: 2025/03/27 17:30:50 by dchernik         ###   ########.fr       */
>>>>>>> efc4016 (Libft was added. A function providing)
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
<<<<<<< HEAD
#include "libft.h"
=======
#include "libft/libft.h"
>>>>>>> efc4016 (Libft was added. A function providing)

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
<<<<<<< HEAD
 *     spos   - starting position of a found
=======
 *     cpos   - position of a found
>>>>>>> efc4016 (Libft was added. A function providing)
 *			    conversion field;
 *     i      - index variable. */
int	ft_printf(char const *format, ...)
{
	static int	pbytes = 0;
	int			i;
	int			cpos;
	int			args_num;
	void		*arg;
	va_list		args;

	i = 0;
	args_num = count_convs(format);
	printf("args_num = %d\n", args_num);
	va_start(vl, args_num);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
<<<<<<< HEAD
			spos = i + 1;
=======
			cpos = i + 1;
>>>>>>> efc4016 (Libft was added. A function providing)
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
<<<<<<< HEAD
					pbytes += process_conv(format, spos, i);
=======
				{
					arg = va_arg(vl, void *);
					pbytes += process_conv(format, arg, cpos);
				}
				else
				{
				}
>>>>>>> efc4016 (Libft was added. A function providing)
			}
		}
		else
		{
			ft_putchar_fd(format[i], STDOUT);
			pbytes++;
		}
		i++;
	}
	va_end(vl);
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
<<<<<<< HEAD
int	process_conv(char const *format, int spos, int epos)
=======
int	process_conv(char const *format, void *arg, int cpos)
>>>>>>> efc4016 (Libft was added. A function providing)
{
	int	pbytes;

	if (format[epos] == 'c')
		pbytes = char_conv(arg, cpos);
	if (format[epos] == 's')
		pbytes = string_conv(arg, cpos);
	if (format[epos] == 'p')
		pbytes = ptr_conv(arg, cpos);
	if (format[epos] == 'd' || format[epos] == 'i')
		pbytes = nbr_conv(arg, cpos);
	if (format[epos] == 'u')
		pbytes = u_nbr_conv(arg, cpos);
	if (format[epos] == 'x' || format[epos] == 'X')
		pbytes = hex_conv(arg, cpos);
	return (pbytes);
}

/* Just to know how many items will
 * contain our array of pointers to
 * all conversions found in the
 * format string. */
<<<<<<< HEAD
int	convs_count(char const *format)
=======
int	count_convs(char const *format)
>>>>>>> efc4016 (Libft was added. A function providing)
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

/* Original printf from Glibc returns -1 only when the percent sign was
 * located at the end of the format string. In this case printf works as
 * it should, outputting everything that was passed to it except for the
 * last single character `%`, which is located at the end of the format
 * string.
 *
 * For instance, in this case:
 * n = printf("%");
 * n will be equal -1, and printf will not output anything
 *
 * ######################################################################
 *
 * When single `%` is located in the middle of the format string (and there
 * is no `%` at the end), printf will try to find corresponding convertion
 * symbol for that `%`, if fails, it will output `%` as it it with all
 * subsequent symbols
 *
 * */
