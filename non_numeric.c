/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_numeric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:31 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/27 21:25:26 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>

/* Processes %c conversion
   args_cnt here is static variable declared in ft_printf.c ! */
int	char_conv(void *arg)
{
	if (arg == NULL)
		write(STDOUT, 0, (size_t)1); // check this!
	else
		write(STDOUT, (char *)arg, (size_t)1);
	return (1);
}

/* Processes %s conversion */
int	string_conv(void *arg)
{
	char	*str;
	int		len;

	if (arg == NULL)
	{
		ft_putstr_fd("(null)", STDOUT);
		return (6);
	}
	str = (char *)arg;
	len = ft_strlen(str);
	ft_putstr_fd(str, STDOUT);
	return (len);
}

/* Processes %p conversion */
int	ptr_conv(void *arg)
{
	size_t	len;
	char	*hexnum;
	
	if (arg == NULL)
	{
		ft_putstr_fd("(nil)", STDOUT);
		return (5);
	}
	hexnum = int_to_hex(*(int *)arg, LOWERCASE);
	write(STDOUT, "0x", (size_t)2);
	ft_putstr_fd(hexnum, STDOUT);
	free(hexnum);
	return (len);
}
