/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_numeric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:29:31 by dchernik          #+#    #+#             */
/*   Updated: 2024/10/30 17:19:01 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	char_conv(char const *format, int spos, int epos)
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

int	string_conv(char const *format, int spos, int epos)
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

int	ptr_conv(char const *format, int spos, int epos)
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
