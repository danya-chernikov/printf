/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 04:35:07 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/28 15:23:23 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdlib.h>

/* Processes %d and %i conversions */
int	nbr_conv(va_list *vl)
{
	int		int_arg;
	char	*num_str;
	char	null;
	int		len;

	null = '0';
	int_arg = va_arg(*vl, int);
	if (int_arg == 0)
	{
		len = 1;
		if (write(STDOUT, &null, (size_t)1) == -1)
			return (-1);
	}
	else
	{
		num_str = ft_itoa(int_arg);
		len = ft_strlen(num_str);
		if (write(STDOUT, num_str, len) == -1)
			return (-1);
		free(num_str);
	}
	return (len);
}

/* Processes %u conversion */
int	u_nbr_conv(va_list *vl)
{
	unsigned int	uint_arg;
	char			*num_str;
	char			null;
	int				len;

	null = '0';
	uint_arg = va_arg(*vl, unsigned int);
	if (uint_arg == 0)
	{
		len = 1;
		if (write(STDOUT, &null, (size_t)1) == -1)
			return (-1);
	}
	else
	{
		num_str = ft_itoa_pos(uint_arg);
		len = ft_strlen(num_str);
		if (write(STDOUT, num_str, len) == -1)
			return (-1);
		free(num_str);
	}
	return (len);
}

/* Processes %x and %X conversions */
int	hex_conv(va_list *vl, int dcase)
{
	char				*hexnum_str;
	unsigned int		hex_arg;
	int					len;
	char				null;

	null = '0';
	hex_arg = va_arg(*vl, unsigned int);
	if (hex_arg == 0)
	{
		len = 1;
		if (write(STDOUT, &null, (size_t)1) == -1)
			return (-1);
	}
	else
	{
		if (dcase == UPPERCASE)
			hexnum_str = int_to_hex(hex_arg, UPPERCASE);
		else
			hexnum_str = int_to_hex(hex_arg, LOWERCASE);
		len = ft_strlen(hexnum_str);
		if (ft_putstr_fd(hexnum_str, STDOUT) == -1)
			return (-1);
		free(hexnum_str);
	}
	return (len);
}
