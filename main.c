/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:30:22 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/28 04:01:04 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int			n;
	int			var;
	int			*var2;
	const char	str[] = "kekekeke";

	var = 10;
	var2 = malloc(1 * sizeof (int));
	if (var2 == NULL)
		return (1);

	n = ft_printf("kekehghdfg | "); ft_printf("n = %d\n", n);
	n = ft_printf("kekeh%%ghdfg | "); ft_printf("n = %d\n", n);
	n = ft_printf("This is a signed integer: %d and %d | ", -123, NULL); ft_printf("n = %d\n", n);
	n = ft_printf("This is another signed integer: %i and %i | ", 0, NULL); ft_printf("n = %d\n", n);
	n = ft_printf("This is an unsigned integer: %u and %u | ", 594, NULL); ft_printf("n = %d\n", n);
	n = ft_printf("This is a char: %c and %c | ", 'A', NULL); ft_printf("n = %d\n", n);
	n = ft_printf("This is a string: \"%s\" and \"%s\" | ", str, NULL); ft_printf("n = %d\n", n);
	n = ft_printf("This is a lowercase hex: %x and %x | ", 0x1AB, NULL); ft_printf("n = %d\n", n);
	n = ft_printf("This is an uppercase hex: %X and %X | ", 0x2CF, NULL); ft_printf("n = %d\n", n);
	n = ft_printf("This is a pointer: %p and %p and %p | ", &var, var2, NULL); ft_printf("n = %d\n", n);
	n = ft_printf("I am just %s saying something. Here we have some numbers: %d, %i | ", str, var, var); ft_printf("n = %d\n", n);
	
	ft_printf("\n\n");

	n = printf("kekehghdfg | "); printf("n = %d\n", n);
	n = printf("kekeh%%ghdfg | "); printf("n = %d\n", n);
	n = printf("This is a signed integer: %d and %d | ", -123, NULL); printf("n = %d\n", n);
	n = printf("This is another signed integer: %i and %i | ", 0, NULL); printf("n = %d\n", n);
	n = printf("This is an unsigned integer: %u and %u | ", 594, NULL); printf("n = %d\n", n);
	n = printf("This is a char: %c and %c | ", 'A', NULL); printf("n = %d\n", n);
	n = printf("This is a string: \"%s\" and \"%s\" | ", str, NULL); printf("n = %d\n", n);
	n = printf("This is a lowercase hex: %x and %x | ", 0x1AB, NULL); printf("n = %d\n", n);
	n = printf("This is an uppercase hex: %X and %X | ", 0x2CF, NULL); printf("n = %d\n", n);
	n = printf("This is a pointer: %p and %p and %p | ", &var, var2, NULL); printf("n = %d\n", n);
	n = printf("I am just %s saying something. Here we have some numbers: %d, %i | ", str, var, var); printf("n = %d\n", n);

	return (0);
}
