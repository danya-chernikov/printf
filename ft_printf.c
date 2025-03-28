/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 04:35:20 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/28 12:04:55 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
 *     cpos   - position of a found
 *			    conversion field;
 *     i      - index variable. */
int	ft_printf(char const *format, ...)
{
	int			pbytes;
	va_list		vl;

	pbytes = 0;
	va_start(vl, format);
	parse_format_str(format, &vl, &pbytes);
	va_end(vl);
	return (pbytes);
}

void	parse_format_str(char const *format, va_list *vl, int *pbytes)
{
	int	res;
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			res = process_percent(format, vl, pbytes, &i);
			if (res == 0)
				break ;
			else if (res == 1)
				continue ;
		}
		else
		{
			ft_putchar_fd(format[i], STDOUT);
			(*pbytes)++;
		}
		i++;
	}
}

int	process_percent(char const *format, va_list *vl, int *pbytes, int *i)
{
	int	cpos;

	cpos = *i + 1;
	if (format[*i + 1] == '\0')
	{
		*pbytes = -1;
		return (0);
	}
	if (next_sym_is_percent(format, i))
	{
		*pbytes = *pbytes + 1;
		return (1);
	}
	else
	{
		while (!is_conv(format[*i]) && format[*i] != '\0')
			*i = *i + 1;
		if (is_conv(format[*i]))
			*pbytes = *pbytes + process_conv(format, vl, cpos);
	}
	return (2);
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
int	process_conv(char const *format, va_list *vl, int cpos)
{
	int	pbytes;

	if (format[cpos] == 'c')
		pbytes = char_conv(vl);
	if (format[cpos] == 's')
		pbytes = string_conv(vl);
	if (format[cpos] == 'p')
		pbytes = ptr_conv(vl);
	if (format[cpos] == 'd' || format[cpos] == 'i')
		pbytes = nbr_conv(vl);
	if (format[cpos] == 'u')
		pbytes = u_nbr_conv(vl);
	if (format[cpos] == 'x')
		pbytes = hex_conv(vl, LOWERCASE);
	if (format[cpos] == 'X')
		pbytes = hex_conv(vl, UPPERCASE);
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
