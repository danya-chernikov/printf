#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	printf(" %d \n", 0);						
	printf(" %d \n", -1);						
	printf(" %d \n", 1);						
	printf(" %d \n", 9);						
	printf(" %d \n", 10);						
	printf(" %d \n", 11);						
	printf(" %d \n", 15);						
	printf(" %d \n", 16);						
	printf(" %d \n", 17);						
	printf(" %d \n", 99);						
	printf(" %d \n", 100);						
	printf(" %d \n", 101);						
	printf(" %d \n", -9);						
	printf(" %d \n", -10);						
	printf(" %d \n", -11);						
	printf(" %d \n", -14);						
	printf(" %d \n", -15);						
	printf(" %d \n", -16);						
	printf(" %d \n", -99);						
	printf(" %d \n", -100);						
	printf(" %d \n", -101);						
	printf(" %d \n", INT_MAX);					
	printf(" %d \n", INT_MIN);					
	printf(" %d \n", LONG_MAX);					
	printf(" %d \n", LONG_MIN);					
	printf(" %d \n", UINT_MAX);					
	printf(" %d \n", ULONG_MAX);				
	printf(" %d \n", 9223372036854775807LL);

	printf(" %d %d %d %d %d %d %d\n\n\n\n",			
	INT_MAX, INT_MIN, LONG_MAX, LONG_MIN,		
	ULONG_MAX, 0, -42);							


	fflush(stdout);

	ft_printf(" %d \n", 0);
	ft_printf(" %d \n", -1);
	ft_printf(" %d \n", 1);
	ft_printf(" %d \n", 9);
	ft_printf(" %d \n", 10);
	ft_printf(" %d \n", 11);
	ft_printf(" %d \n", 15);
	ft_printf(" %d \n", 16);
	ft_printf(" %d \n", 17);
	ft_printf(" %d \n", 99);
	ft_printf(" %d \n", 100);
	ft_printf(" %d \n", 101);
	ft_printf(" %d \n", -9);
	ft_printf(" %d \n", -10);
	ft_printf(" %d \n", -11);
	ft_printf(" %d \n", -14);
	ft_printf(" %d \n", -15);
	ft_printf(" %d \n", -16);
	ft_printf(" %d \n", -99);		
	ft_printf(" %d \n", -100);
	ft_printf(" %d \n", -101);
	ft_printf(" %d \n", INT_MAX);
	ft_printf(" %d \n", INT_MIN);
	ft_printf(" %d \n", LONG_MAX);
	ft_printf(" %d \n", LONG_MIN);
	ft_printf(" %d \n", UINT_MAX);
	ft_printf(" %d \n", ULONG_MAX);
	ft_printf(" %d \n", 9223372036854775807LL);

	ft_printf(" %d %d %d %d %d %d %d\n",
	INT_MAX, INT_MIN, LONG_MAX, LONG_MIN,
	ULONG_MAX, 0, -42);

	return (0);
}
