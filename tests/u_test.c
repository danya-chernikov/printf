#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	printf(" %u \n", 0);						
	printf(" %u \n", -1);						
	printf(" %u \n", 1);						
	printf(" %u \n", 9);						
	printf(" %u \n", 10);						
	printf(" %u \n", 11);						
	printf(" %u \n", 15);						
	printf(" %u \n", 16);						
	printf(" %u \n", 17);						
	printf(" %u \n", 99);						
	printf(" %u \n", 100);						
	printf(" %u \n", 101);						
	printf(" %u \n", -9);						
	printf(" %u \n", -10);						
	printf(" %u \n", -11);						
	printf(" %u \n", -14);						
	printf(" %u \n", -15);						
	printf(" %u \n", -16);						
	printf(" %u \n", -99);						
	printf(" %u \n", -100);						
	printf(" %u \n", -101);						
	printf(" %u \n", INT_MAX);					
	printf(" %u \n", INT_MIN);					
	printf(" %u \n", LONG_MAX);					
	printf(" %u \n", LONG_MIN);					
	printf(" %u \n", UINT_MAX);					
	printf(" %u \n", ULONG_MAX);				
	printf(" %u \n", 9223372036854775807LL);

	printf(" %u %u %u %u %u %u %u\n\n",
	INT_MAX, INT_MIN, LONG_MAX, LONG_MIN,
	ULONG_MAX, 0, -42);							

	fflush(stdout);

	ft_printf(" %u \n", 0);
	ft_printf(" %u \n", -1);
	ft_printf(" %u \n", 1);
	ft_printf(" %u \n", 9);
	ft_printf(" %u \n", 10);
	ft_printf(" %u \n", 11);
	ft_printf(" %u \n", 15);
	ft_printf(" %u \n", 16);
	ft_printf(" %u \n", 17);
	ft_printf(" %u \n", 99);
	ft_printf(" %u \n", 100);
	ft_printf(" %u \n", 101);
	ft_printf(" %u \n", -9);
	ft_printf(" %u \n", -10);
	ft_printf(" %u \n", -11);
	ft_printf(" %u \n", -14);
	ft_printf(" %u \n", -15);
	ft_printf(" %u \n", -16);
	ft_printf(" %u \n", -99);		
	ft_printf(" %u \n", -100);
	ft_printf(" %u \n", -101);
	ft_printf(" %u \n", INT_MAX);
	ft_printf(" %u \n", INT_MIN);
	ft_printf(" %u \n", LONG_MAX);
	ft_printf(" %u \n", LONG_MIN);
	ft_printf(" %u \n", UINT_MAX);
	ft_printf(" %u \n", ULONG_MAX);
	ft_printf(" %u \n", 9223372036854775807LL);


	ft_printf(" %u %u %u %u %u %u %u\n",
	INT_MAX, INT_MIN, LONG_MAX, LONG_MIN,
	ULONG_MAX, 0, -42);

	return (0);
}
