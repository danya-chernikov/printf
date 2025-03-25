/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_numeric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:31 by dchernik          #+#    #+#             */
/*   Updated: 2024/10/30 19:01:39 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

/* Processes %c conversion
   args_cnt here is static variable declared in ft_printf.c ! */
int	char_conv(char const *format, int spos, int epos, int args_cnt)
{
	printf("\"\n");
	return (0);
}

/* Processes %s conversion */
int	string_conv(char const *format, int spos, int epos, int args_cnt)
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

/* Processes %p conversion */
int	ptr_conv(char const *format, int spos, int epos, int args_cnt)
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
