/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 04:35:20 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/28 15:33:40 by dchernik         ###   ########.fr       */
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
	int			res;
	va_list		vl;

	pbytes = 0;
	va_start(vl, format);
	res = parse_format_str(format, &vl, &pbytes);
	if (res == -1)
		return (-1);
	va_end(vl);
	return (pbytes);
}

/* Returns 0 on success */
int	parse_format_str(char const *format, va_list *vl, int *pbytes)
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
			else if (res == -1)
				return (-1);	
		}
		else
		{
			write(STDOUT, &format[i], (size_t)1);
			(*pbytes)++;
		}
		i++;
	}
	return (0);
}

int	process_percent(char const *format, va_list *vl, int *pbytes, int *i)
{
	int	cpos;
	int	res;

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
		{
			res = process_conv(format, vl, cpos);
			if (res == -1)
				return (-1);
			*pbytes = *pbytes + res;
		}
	}
	return (2);
}

/* For each conversion calls the appropriate function
 * to handle it */
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
	char	percent;

	percent = '%';
	if (format[*i + 1] == '%')
	{
		write(STDOUT, &percent, (size_t)1);
		*i += 2;
		return (1);
	}
	return (0);
}
