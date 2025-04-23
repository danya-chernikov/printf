/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:47:30 by dchernik          #+#    #+#             */
/*   Updated: 2025/04/21 13:56:32 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main()
{
	char	*null_ptr;
	int		n;

	null_ptr = NULL;

	// Too few arguemnts
	ft_printf("Too few arguments\n");

	ft_printf("%s", "n = ft_printf(\"We are %s some %s, and %s %p we are "
		   "very %d happy %d about %f it\\n\", \"printing\", \"data\", "
		   "null_ptr, null_ptr, 3485938);\");\n\n");

	n = ft_printf("We are %s some %s, and %s (%p) we are very "
			   "%d happy %d about %f it\n",
			   "printing", "data", null_ptr, null_ptr, 3485938);

	ft_printf("\nn = %d\n", n);

	ft_printf("\n##################################################\n\n");

	// Too many arguments
	ft_printf("Too many arguments\n");

	ft_printf("%s", "n = ft_printf(\"We are %s some %s, and %s %p we are very "
		   "%d happy %d about %f it\\n\", \"printing\", \"data\","
		   " null_ptr, null_ptr, 3485938, 0, 3.1415926535, \"kekek\","
		   " 1000, 2.719281928459045);\");\n\n");

	n = ft_printf("We are %s some %s, and %s (%p) we are very %d happy"
			   " %d about %f it\n",
			   "printing", "data", null_ptr, null_ptr, 3485938, 0,
			   3.1415926535, "kekek", 1000, 2.719281928459045);

	ft_printf("\nn = %d\n", n);

	ft_printf("\n##################################################\n\n");

	// The '%' symbol at the end of the format string
	ft_printf("The %% symbol at the end of the format string\n");

	ft_printf("%s", "n = ft_printf(\"We are %s some %s, and %s %p we % are %% very "
		   "%d happy %d about %f it\\n%\","
		   "\"printing\", \"data\", null_ptr, null_ptr, 1.0,"
		   "3485938, 0, 3.1415926535);\n\n");

	n = ft_printf("We are %s some %s, and %s (%p) we % are %% very "
			   "%d happy %d about %f it\n%",
			   "printing", "data", null_ptr, null_ptr, 1.0,
			   3485938, 0, 3.1415926535);

	ft_printf("n = %d\n\n", n);

	ft_printf("%s", "n = ft_printf(\"%\");\n");

	n = ft_printf("%");

	ft_printf("\nn = %d\n", n);

	ft_printf("\n##################################################\n\n");

	// Impossible specificator
	ft_printf("Impossible specificator\n");

	ft_printf("%s", "n = ft_printf(\"We are %s some %s, and %s %p we % are %% ve%wry\""
		   " %d happy %d about %f it\\n,"
		   "printing\", \"data\", null_ptr, null_ptr, 1.0,"
		   "3485938, 0, 3.1415926535);\");\n\n");

	n = ft_printf("We are %s some %s, and %s (%p) we % are %% ve%wry"
			   " %d happy %d about %f it\n",
			   "printing", "data", null_ptr, null_ptr, 1.0,
			   3485938, 0, 3.1415926535);

	ft_printf("n = %d\n\n", n);

	ft_printf("\n##################################################\n\n");

	ft_printf("Escape sequences\n");
	ft_printf("\a \\ \b \r \" \f \t \n \' \v \? \e \z %% | %s",
		   "\a \\ \b \r \" \f \t \n \' \v \? \e \z %%");

	ft_printf("\n\n");

	ft_printf("\\ %s \\", "hello\\_\\world\n");

	printf("\nchar = %c\nxlower = %x\nxupper = %X\nptr = %p\nstr = %s\n", NULL, NULL, NULL, NULL, NULL);

	printf("\n%x\n%X\n%x\n%X\n%x\n%X\n", NULL, NULL, 0, 1, 100, 1000);
	
	int	a = 4343;
	printf("\n%p\n%p\n%p\n%p\n%p\n%p\n", NULL, 0, 1, 100, 1000, &a);

	return (0);
}
