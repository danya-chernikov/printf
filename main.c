/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:30:22 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/28 01:06:57 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int			var;
	const char	str[] = "kekekeke";

	var = 10;
	ft_printf("kekehghdfg\n");
	ft_printf("kekeh%%ghdfg\n");
	ft_printf("This is a signed integer: %d\n", -123);
	ft_printf("This is an unsigned integer: %u\n", 594);
	ft_printf("This is a char: %c\n", 'A');
	ft_printf("This is a string: %s\n", str);
	ft_printf("This is a lowercase hex: %x\n", 0x1AB);
	ft_printf("This is an uppercase hex: %X\n", 0x2CF);
	ft_printf("This is a pointer: %p\n", &var);
	/*ft_printf("I am just %s saying something. Here we have some numbers: %d, %i\n", str, var, var);*/
	return (0);
}
