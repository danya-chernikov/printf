/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:25 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/27 19:32:16 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>

/* Processes %u conversion */
int	nbr_conv(void *arg, int cpos)
{
	printf("\n\"");
	while (spos < epos)
	{
		printf("%c", format[spos]);
		spos++;
	}
	printf("\"\n");
	return (0);
}

/* Processes %d and %i conversions */
int	u_nbr_conv(void *arg, int cpos)
{
	printf("\n\"");
	while (spos < epos)
	{
		printf("%c", format[spos]);
		spos++;
	}
	printf("\"\n");
	return (0);
}

/* Processes %x and %X conversions */
int	hex_conv_upper(void *arg, int cpos)
{
	char	*hexnum;
	int		len;


	return (len);
}

int	hex_conv_lower(void *arg, int cpos)
{
	char	*hexnum;
	int		len;


	return (len);
}
