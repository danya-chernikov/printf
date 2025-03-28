/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_numeric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:31 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/28 03:23:09 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <unistd.h>
#include <stdlib.h>

/* Processes %c conversion
   args_cnt here is static variable declared in ft_printf.c ! */
int	char_conv(va_list *vl)
{
	char	*char_arg;
	char	null;
	size_t	len;

	len = 1;
	null = '\0';
	char_arg = va_arg(*vl, char *);
	if (char_arg == NULL)
		write(STDOUT, &null, len); // check this!
	else
		write(STDOUT, char_arg, len);
	return (len);
}

/* Processes %s conversion */
int	string_conv(va_list *vl)
{
	char	*str_arg;
	size_t	len;

	str_arg = va_arg(*vl, char *);
	if (str_arg == NULL)
	{
		ft_putstr_fd("(null)", STDOUT);
		len = 6;
	}
	else
	{
		len = ft_strlen(str_arg);
		ft_putstr_fd(str_arg, STDOUT);
	}
	return (len);
}

/* Processes %p conversion */
int	ptr_conv(va_list *vl)
{
	char			*hexnum;
	unsigned int	uint_arg;
	size_t			len;
	
	uint_arg = va_arg(*vl, unsigned int);
	if (uint_arg == 0)
	{
		ft_putstr_fd("(nil)", STDOUT);
		len = 5;
	}
	else
	{
		hexnum = int_to_hex(uint_arg, LOWERCASE);
		len = ft_strlen(hexnum) + 2;
		write(STDOUT, "0x", (size_t)2);
		ft_putstr_fd(hexnum, STDOUT);
		free(hexnum);
	}
	return (len);
}
