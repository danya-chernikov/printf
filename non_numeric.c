/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_numeric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:31 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/27 19:32:15 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>

/* Processes %c conversion
   args_cnt here is static variable declared in ft_printf.c ! */
int	char_conv(void *arg, int cpos)
{
	if (arg == NULL)
		write(STDOUT, 0, (size_t)1); // check this!
	else
		write(STDOUT, (char *)arg, (size_t)1);
	return (1);
}

/* Processes %s conversion */
int	string_conv(void *arg, int cpos)
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
int	ptr_conv(void *arg, int cpos)
{

	return (len);
}
