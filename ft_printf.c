/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:29 by dchernik          #+#    #+#             */
/*   Updated: 2024/10/30 17:46:20 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

/* pbytes - number of bytes that ft_printf outputed
   spos   - starting position of a found conversion
   i      - index variable
   In a loop, we process all symbols in the format string.
   If we find two consecutive '%' symbols, we print one of them.
   If the symbol following '%' is not another '%', we continue until
   we find a conversion symbol or reach the end of the string.
   When we find a conversion symbol corresponding to that '%', we call
   process_conv(), which will call the appropriate function to handle
   the conversion. */
int	ft_printf(char const *format, ...)
{
	static int	pbytes;
	int			i;
	int			spos;

	i = 0;
	pbytes = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			spos = i + 1;
			if (next_sym_is_percent(format, &i))
				continue ;
			while (!is_conv(format[i]) && format[i] != '\0')
				i++;
			if (is_conv(format[i]))
				process_conv(format, spos, i);
		}
		else
			ft_putchar_fd(format[i], STDOUT);
		pbytes++;
		i++;
	}
	return (pbytes);
}

/* Determines if the symbol after the i position is a percent symbol.
   If so, it prints '%' and skips the i + 1 position */
int	next_sym_is_percent(char const *format, int *i)
{
	if ((format[*i + 1] != '\0') && (format[*i + 1] == '%'))
	{
		ft_putchar_fd('%', STDOUT);
		*i += 2;
		return (1);
	}
	return (0);
}

int	process_conv(char const *format, int spos, int epos)
{
	int	pbytes;

	if (format[epos] == 'c')
		pbytes = char_conv(format, spos, epos);
	if (format[epos] == 's')
		pbytes = string_conv(format, spos, epos);
	if (format[epos] == 'p')
		pbytes = ptr_conv(format, spos, epos);
	if (format[epos] == 'd' || format[epos] == 'i')
		pbytes = nbr_conv(format, spos, epos);
	if (format[epos] == 'u')
		pbytes = u_nbr_conv(format, spos, epos);
	if (format[epos] == 'x' || format[epos] == 'X')
		pbytes = hex_conv(format, spos, epos);
	return (pbytes);
}

/* Just to know how many items will contain our array of pointers to all
   conversions found in the format string */
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

/* Determines if a symbol belongs to a conversion specifier symbols group */
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
