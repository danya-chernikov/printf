/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:30:22 by dchernik          #+#    #+#             */
/*   Updated: 2024/10/30 17:17:26 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("kekehghdfg\n");
	ft_printf("kekeh%%ghdfg\n");
	ft_printf("I am just %10s saying something. Here we have some\
numbers: %-15d, %05i\n");
	ft_printf("This is a pointer: %p\n");
	return (0);
}
