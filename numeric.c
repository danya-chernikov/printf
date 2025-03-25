/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:25 by dchernik          #+#    #+#             */
/*   Updated: 2024/10/30 18:51:00 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

/* Processes %u conversion */
int	nbr_conv(char const *format, int spos, int epos, int args_cnt)
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
int	u_nbr_conv(char const *format, int spos, int epos, int args_cnt)
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
int	hex_conv(char const *format, int spos, int epos, int args_cnt)
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
