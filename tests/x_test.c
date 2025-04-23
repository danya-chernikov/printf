#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	printf(" %x \n", 0);						
	printf(" %x \n", -1);						
	printf(" %x \n", 1);						
	printf(" %x \n", 9);						
	printf(" %x \n", 10);						
	printf(" %x \n", 11);						
	printf(" %x \n", 15);						
	printf(" %x \n", 16);						
	printf(" %x \n", 17);						
	printf(" %x \n", 99);						
	printf(" %x \n", 100);						
	printf(" %x \n", 101);						
	printf(" %x \n", -9);						
	printf(" %x \n", -10);						
	printf(" %x \n", -11);						
	printf(" %x \n", -14);						
	printf(" %x \n", -15);						
	printf(" %x \n", -16);						
	printf(" %x \n", -99);						
	printf(" %x \n", -100);						
	printf(" %x \n", -101);						
	printf(" %x \n", INT_MAX);					
	printf(" %x \n", INT_MIN);					
	printf(" %x \n", LONG_MAX);					
	printf(" %x \n", LONG_MIN);					
	printf(" %x \n", UINT_MAX);					
	printf(" %x \n", ULONG_MAX);				
	printf(" %x \n", 9223372036854775807LL);
	printf(" %x \n", 9223371972429414398LL);

	printf(" %x %x %x %x %x %x %x\n",
	INT_MAX, INT_MIN, LONG_MAX, LONG_MIN,
	ULONG_MAX, 0, -42);							

	printf(" %x \n", 42);
	printf(" %x \n\n\n", -42);

	fflush(stdout);

	ft_printf(" %x \n", 0);
	ft_printf(" %x \n", -1);
	ft_printf(" %x \n", 1);
	ft_printf(" %x \n", 9);
	ft_printf(" %x \n", 10);
	ft_printf(" %x \n", 11);
	ft_printf(" %x \n", 15);
	ft_printf(" %x \n", 16);
	ft_printf(" %x \n", 17);
	ft_printf(" %x \n", 99);
	ft_printf(" %x \n", 100);
	ft_printf(" %x \n", 101);
	ft_printf(" %x \n", -9);
	ft_printf(" %x \n", -10);
	ft_printf(" %x \n", -11);
	ft_printf(" %x \n", -14);
	ft_printf(" %x \n", -15);
	ft_printf(" %x \n", -16);
	ft_printf(" %x \n", -99);		
	ft_printf(" %x \n", -100);
	ft_printf(" %x \n", -101);
	ft_printf(" %x \n", INT_MAX);
	ft_printf(" %x \n", INT_MIN);
	ft_printf(" %x \n", LONG_MAX);
	ft_printf(" %x \n", LONG_MIN);
	ft_printf(" %x \n", UINT_MAX);
	ft_printf(" %x \n", ULONG_MAX);
	ft_printf(" %x \n", 9223372036854775807LL);

	ft_printf(" %x \n", 9223371972429414398LL);

	ft_printf(" %x %x %x %x %x %x %x\n",
	INT_MAX, INT_MIN, LONG_MAX, LONG_MIN,
	ULONG_MAX, 0, -42);

	ft_printf(" %x \n", 42);
	ft_printf(" %x \n", -42);

	return (0);
}
