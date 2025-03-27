/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:25 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/27 21:24:40 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>

/* Processes %u conversion */
int	nbr_conv(void *arg)
{
	size_t	len;
	char	*num;

	num = ft_itoa(*(int *)arg);
	len = ft_strlen(num);
	write(STDOUT, num, len);
	return (len);
}

/* Processes %d and %i conversions */
int	u_nbr_conv(void *arg)
{
	size_t	len;
	char	*num;

	num = ft_itoa(*(unsigned int *)arg);
	len = ft_strlen(num);
	write(STDOUT, num, len);
	return (len);
}

/* Processes %X conversion */
int	hex_conv_upper(void *arg)
{
	size_t	len;
	char	*hexnum;
	
	if (arg == NULL)
	{
		ft_putchar_fd('0', STDOUT);
		return (1);
	}
	else
	{
		hexnum = int_to_hex(*(int *)arg, UPPERCASE);
		ft_putstr_fd(hexnum, STDOUT);
		free(hexnum);
	}
	return (len);
}

/* Processes %x conversion */
int	hex_conv_lower(void *arg)
{
	size_t	len;
	char	*hexnum;

	if (arg == NULL)
	{
		ft_putchar_fd('0', STDOUT);
		return (1);
	}
	else
	{
		hexnum = int_to_hex(*(int *)arg, LOWERCASE);
		ft_putstr_fd(hexnum, STDOUT);
		free(hexnum);
	}
	return (len);
}
