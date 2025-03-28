/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_numeric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 04:35:03 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/28 15:27:13 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdlib.h>

/* Processes %c conversion
   args_cnt here is static variable declared in ft_printf.c ! */
int	char_conv(va_list *vl)
{
	int		char_arg;
	char	null;
	int		len;

	len = 1;
	null = '\0';
	char_arg = va_arg(*vl, int);
	if (char_arg == 0)
	{
		if (write(STDOUT, &null, len) == -1)
			return (-1);
	}
	else
	{
		if (write(STDOUT, &char_arg, len) == -1)
			return (-1);
		
	}
	return (len);
}

/* Processes %s conversion */
int	string_conv(va_list *vl)
{
	char	*str_arg;
	int		len;

	str_arg = va_arg(*vl, char *);
	if (str_arg == NULL)
	{
		len = 6;
		if (ft_putstr_fd("(null)", STDOUT) == -1)
			return (-1);
	}
	else
	{
		len = ft_strlen(str_arg);
		if (ft_putstr_fd(str_arg, STDOUT) == -1)
			return (-1);
	}
	return (len);
}

/* Processes %p conversion */
int	ptr_conv(va_list *vl)
{
	char				*hexnum;
	unsigned long long	uint_arg;
	int					len;

	uint_arg = va_arg(*vl, unsigned long long);
	if (uint_arg == 0)
	{
		len = 5;
		if (ft_putstr_fd("(nil)", STDOUT) == -1)
			return (-1);
	}
	else
	{
		hexnum = int_to_hex(uint_arg, LOWERCASE);
		len = ft_strlen(hexnum) + 2;
		if (write(STDOUT, "0x", (size_t)2) == -1)
			return (-1);
		if (ft_putstr_fd(hexnum, STDOUT) == -1)
			return (-1);
		free(hexnum);
	}
	return (len);
}
