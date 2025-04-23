#include <stdio.h>

typedef unsigned char		uc;
typedef unsigned short		us;
typedef unsigned int		ui;
typedef unsigned long		ul;
typedef unsigned long long	ull;

int main()
{
	const char *str = "hello, world";
    const char *str1 = "lel";
    int	n1, n2;
    int num1 = 859422;
    int num2 = 1024;
    int hexnum = 0xAAF;
    int octnum = 0433;
    int min_fld_wid = 10;
    int prec = 4;
    float fnum1 = 3.1415926535;
    float fnum2 = 2.718281828459045;
    float fnum3 = -565.3349013488;
    const char *empstr = "";
    char ch = 'A';
	int n; // number of bytes printf printed

	// the int argument is converted to an unsigned char, and the resulting character  is  written	
	// testing unsigned char with %c
	printf("\nTesting %%c\n");
	printf("\t1. pf(\"%%c\", -129):\t\t\t");		n = printf("'%c'", -129);	 printf("\t\t\t%d\n", n);
	printf("\t2. pf(\"%%c\", -128):\t\t\t");		n = printf("'%c'", -128);	 printf("\t\t\t%d\n", n);
	printf("\t3. pf(\"%%c\", -127):\t\t\t");		n = printf("'%c'", -127);	 printf("\t\t\t%d\n", n);
	printf("\t4. pf(\"%%c\", -10):\t\t\t");			n = printf("'%c'", -10);	 printf("\t\t\t%d\n", n);
	printf("\t5. pf(\"%%c\", 0):\t\t\t\t");			n = printf("'%c'", 0);	     printf("\t\t\t%d\n", n);
	printf("\t6. pf(\"%%c\", 'A'):\t\t\t");			n = printf("'%c'", 'A');	 printf("\t\t\t%d\n", n);
	printf("\t7. pf(\"%%c\", 100):\t\t\t");			n = printf("'%c'", 100);	 printf("\t\t\t%d\n", n);
	printf("\t8. pf(\"%%c\", 126):\t\t\t");			n = printf("'%c'", 126);	 printf("\t\t\t%d\n", n);
	printf("\t9. pf(\"%%c\", 127):\t\t\t");			n = printf("'%c'", 127);	 printf("\t\t\t%d\n", n);
	printf("\t10. pf(\"%%c\", 128):\t\t\t");		n = printf("'%c'", 128);	 printf("\t\t\t%d\n", n);
	printf("\t11. pf(\"%%c\", 255):\t\t\t");		n = printf("'%c'", 255);	 printf("\t\t\t%d\n", n);
	printf("\t12. pf(\"%%c\", 256):\t\t\t");		n = printf("'%c'", 256);	 printf("\t\t\t%d\n", n);
	printf("\t13. pf(\"%%c\", 257):\t\t\t");		n = printf("'%c'", 257);	 printf("\t\t\t%d\n", n);
	printf("\t14. pf(\"%%c\", (int)63):\t\t\t");	n = printf("'%c'", (int)63); printf("\t\t\t%d\n", n);
	printf("\t15. pf(\":%%hhd:\", %c):\t\t\t", ch);	n = printf(":%hhd:", ch);	 printf("\t\t\t%d\n", n);
	// conversion %c can have only '-' flag and can't have precision
	// testing %c with flags and width
	printf("\nTesting %%c with flags and width\n");
	printf("\t16. pf(\":%%5c:\", 56):\t\t\t");		n = printf(":%5c:", 56);	 printf("\t\t\t%d\n", n);
	printf("\t17. pf(\":%%-5c:\", 56):\t\t\t");		n = printf(":%-5c:", 56);	 printf("\t\t\t%d\n", n);


	// testing %s
	printf("\n\nTesting %%s\n");
	printf("\t1.  pf(\":%%s:\", \"a string\"):\t\t");		n = printf(":%s:", "a string");			printf("\t\t%d\n", n);
    printf("\t2.  pf(\":%%s:\", \"%s\"):\t\t", str);		n = printf(":%s:", str);				printf("\t\t%d\n", n);
    printf("\t3.  pf(\":%%10s:\", \"%s\"):\t", str);		n = printf(":%10s:", str);				printf("\t\t%d\n", n);
    printf("\t4.  pf(\":%%5s:\", \"%s\"):\t", str);			n = printf(":%5s:", str1);				printf("\t\t\t%d\n", n);
    printf("\t5.  pf(\":%%5.2s:\", \"%s\"):\t", str);		n = printf(":%5.2s:", str1);			printf("\t\t\t%d\n", n);
    printf("\t6.  pf(\":%%-5.2s:\", \"%s\"):\t", str);		n = printf(":%-5.2s:", str1);			printf("\t\t\t%d\n", n);
    printf("\t7.  pf(\":%%.10s:\", \"%s\"):\t", str);		n = printf(":%.10s:", str);				printf("\t\t%d\n", n);
    printf("\t8.  pf(\":%%.s:\", \"%s\"):\t", str);			n = printf(":%.s:", str);				printf("\t\t\t%d\n", n);
    printf("\t9.  pf(\":%%-10s:\", \"%s\"):\t", str);		n = printf(":%-10s:", str);				printf("\t\t%d\n", n);
    printf("\t10. pf(\":%%.15s:\", \"%s\"):\t", str);		n = printf(":%.15s:", str);				printf("\t\t%d\n", n);
    printf("\t11. pf(\":%%-15s:\", \"%s\"):\t", str);		n = printf(":%-15s:", str);				printf("\t%d\n", n);
    printf("\t12. pf(\":%%-.15s:\", \"%s\"):\t", str);		n = printf(":%-.15s:", str);			printf("\t\t%d\n", n);
    printf("\t13. pf(\":%%15.10s:\", \"%s\"):\t", str);		n = printf(":%15.10s:", str);			printf("\t%d\n", n);
    printf("\t14. pf(\":%%-15.11s:\", \"%s\"):\t", str);	n = printf(":%-15.11s:", str);			printf("\t%d\n", n);
    printf("\t15. pf(\":%%s:\", \"%s\"):\t\t", str);		n = printf(":%s:", empstr);				printf("\t\t\t%d\n", n);
    printf("\t16. pf(\":%%1$-.*2$s:\", \"%s\"):\t", str);	n = printf(":%1$-.*2$s:", "fwefwff", 4);printf("\t\t\t%d\n", n);


	// testing %p
	printf("\n\nTesting %%p\n");
	printf("\t1.  pf(\":%%p:\", (void *)32):\t\t");			n = printf(":%p:", (void *)32);		printf("\t\t\t%d\n", n);
	int var1;
	printf("\n\t    int var1;\n");
	printf("\t2.  pf(\":%%p:\", (void *)&var1):\t\t");		n = printf(":%p:", (void *)&var1);	printf("\t%d\n", n);
	int *ptr1 = NULL;
	printf("\n\t    int *ptr1 = NULL;\n");
	printf("\t3.  pf(\":%%p:\", ptr1):\t\t\t");				n = printf(":%p:", ptr1);			printf("\t\t\t%d\n", n);
	ptr1 = &var1;
	printf("\n\t    ptr1 = var1;\n");
	printf("\t4.  pf(\":%%p:\", ptr1):\t\t\t");				n = printf(":%p:", ptr1);			printf("\t%d\n", n);
	printf("\t5.  pf(\":%%p:\", &ptr1):\t\t\t");			n = printf(":%p:", &ptr1);			printf("\t%d\n", n);
	// conversion %p can have only '-' flag and can't have precision
	// testing %p with flags and width
	printf("\nTesting %%p with flags and width\n");
	printf("\t6.  pf(\":%%18p:\", &ptr1):\t\t");			n = printf(":%18p:", &ptr1);		printf("\t%d\n", n);
	printf("\t7.  pf(\":%%-18p:\", &ptr1):\t\t");			n = printf(":%-18p:", &ptr1);		printf("\t%d\n", n);

 
	// testing %d
	printf("\n\nTesting %%d\n");
	printf("\t1.  pf(\":%%10d:\", -100):\t\t\t");						n = printf(":%10d:", -100);				   printf("\t\t%d\n", n);
	printf("\t2.  pf(\":%%-10d:\", -100):\t\t");						n = printf(":%-10d:", -100);			   printf("\t\t%d\n", n);
	printf("\t3.  pf(\":%%+d:\", 100):\t\t\t");							n = printf(":%+d:", 100);				   printf("\t\t\t%d\n", n);
	printf("\t4.  pf(\":%%-+10d:\", -100):\t\t");						n = printf(":%-+10d:", -100);			   printf("\t\t%d\n", n);
	printf("\t5.  pf(\":%% d:\", 100):\t\t\t");							n = printf(":% d:", 100);				   printf("\t\t\t%d\n", n);
	printf("\t6.  pf(\":%%- 10d:\", -100):\t\t");						n = printf(":%- 10d:", -100);			   printf("\t\t%d\n", n);
	printf("\t7.  pf(\":%%-+10d:\", 100):\t\t");						n = printf(":%-+10d:", 100);			   printf("\t\t%d\n", n);
	printf("\t8.  pf(\":%%010d:\", -100):\t\t");						n = printf(":%010d:", -100);			   printf("\t\t%d\n", n);
	printf("\t9.  pf(\":%%-10d:\", -100):\t\t");						n = printf(":%-10d:", -100);			   printf("\t\t%d\n", n);
	printf("\t10. pf(\":%%+010d:\", -100):\t\t");						n = printf(":%+010d:", -100);			   printf("\t\t%d\n", n);
	printf("\t11. pf(\":%%10.*d:\", -100):\t\t");						n = printf(":%10.*d:", -4, -100);		   printf("\t\t%d\n", n);
	printf("\t12. pf(\":%%1$*2$.*3$d:\", -100):\t\t");					n = printf(":%1$*2$.*3$d:", -100, 10, 5);  printf("\t\t%d\n", n);
	printf("\t13. pf(\":%%.d:\", -100):\t\t\t");						n = printf(":%.d:", -100);				   printf("\t\t\t%d\n", n);
	printf("\t14. pf(\":%%-5d:\", 100):\t\t\t");						n = printf(":%-5d:", 100);				   printf("\t\t\t%d\n", n);
	printf("\t15. pf(\":%%-+10d:\", %d):\t\t", num1);					n = printf(":%-+10d:", num1);			   printf("\t\t%d\n", n);
    printf("\t16. pf(\":%%.5d:\", %d):\t\t\t", num2);					n = printf(":%.5d:", num2);				   printf("\t\t\t%d\n", n);
    printf("\t17. pf(\":%%.7d:\", %d):\t\t\t", num2);					n = printf(":%.7d:", num2);				   printf("\t\t%d\n", n);
    printf("\t18. pf(\":%%*d:\", %d, %d):\t\t", min_fld_wid, num2);		n = printf(":%*d:", min_fld_wid, num2);	   printf("\t\t%d\n", n);
    printf("\t19. pf(\":%%2$*1$d:\", %d, %d):\t\t", min_fld_wid, num2);	n = printf(":%2$*1$d:", min_fld_wid, num2);printf("\t\t%d\n", n);
    // When 0 is printed with an explicit precision 0, the output is empty (man 3 printf line 193)
    printf("\t20. pf(\":%%d:\", 0):\t\t\t");							n = printf(":%d:", 0);					   printf("\t\t\t%d\n", n);
    printf("\t21. pf(\":%%.0d:\", 0):\t\t\t");							n = printf(":%.0d:", 0);				   printf("\t\t\t%d\n", n);
    // The default precision is 1
    printf("\t22. pf(\":%%.1d:\", 1):\t\t\t");							n = printf(":%.1d:", 1);				   printf("\t\t\t%d\n", n);
    printf("\t23. pf(\":%%.1d:\", 10):\t\t\t");							n = printf(":%.1d:", 10);				   printf("\t\t\t%d\n", n);


	// testing %i
	// works absolutely the same way as %d
	printf("\nTesting %%i\n");
	// we received a warning when trying to pass a number outside the [INT_MIN; INT_MAX] range
	printf("\t1.  pf(\":%%i:\", -2147483647):\t\t");n = printf(":%i:", -2147483647);printf("\t\t%d\n", n);
	printf("\t2.  pf(\":%%i:\", -2147483646):\t\t");n = printf(":%i:", -2147483646);printf("\t\t%d\n", n);
	printf("\t3.  pf(\":%%i:\", -199):\t\t\t");		n = printf(":%i:", -199);		printf("\t\t\t%d\n", n);
	printf("\t4.  pf(\":%%i:\", -1):\t\t\t");		n = printf(":%i:", -1);			printf("\t\t\t%d\n", n);
	printf("\t5.  pf(\":%%i:\", 0):\t\t\t");		n = printf(":%i:", 0);			printf("\t\t\t%d\n", n);
	printf("\t6.  pf(\":%%i:\", 100):\t\t\t");		n = printf(":%i:", 100);		printf("\t\t\t%d\n", n);
	printf("\t7.  pf(\":%%i:\", 65535):\t\t\t");	n = printf(":%i:", 65535);		printf("\t\t\t%d\n", n);
	printf("\t8.  pf(\":%%i:\", 2147483647):\t\t");	n = printf(":%i:", 2147483646);	printf("\t\t%d\n", n);
	printf("\t9.  pf(\":%%i:\", 2147483647):\t\t");	n = printf(":%i:", 2147483647);	printf("\t\t%d\n", n);
	int dword = 2147483646;
	short word = (short)dword;
	us uword = (us)dword;
	printf("\t10. pf(\":%%i:\", word):\t\t\t");		n = printf(":%i:", word);		printf("\t\t\t%d\n", n);
	// what if we cast a positive number (int to short) and then passed the negative result to printf with a %u spefifier
	// here word is promoted to int
	printf("\t11. pf(\":%%u:\", word):\t\t\t");		n = printf(":%u:", word);		printf("\t\t%d\n", n);
	// what if we cast to unsigned short and pass it with %u
	// here word is promoted to unsigned int but the output is different (65534) because the promotion preserves the original
	// bit pattern and treats it as a positive value // here word is promoted to unsigned int but the output
	// is different (65534) because the promotion preserves the original bit pattern and treats it as a positive value
	printf("\t12. pf(\":%%u:\", uword):\t\t\t");	n = printf(":%u:", uword);		printf("\t\t\t%d\n", n);
	// what if we cast to unsigned short and pass it with %i
	printf("\t13. pf(\":%%i:\", uword):\t\t\t");			  n = printf(":%i:", uword);				printf("\t\t\t%d\n", n);
	printf("\t14. pf(\":%%i:\", (uc)2147483647):\t\t");		  n = printf(":%i:", (uc)2147483647);		printf("\t\t\t%d\n", n);
	printf("\t15. pf(\":%%i:\", (char)2147483647):\t");		  n = printf(":%i:", (char)2147483647);		printf("\t\t\t%d\n", n);
	printf("\t16. pf(\":%%i:\", (us)2147483647):\t\t");		  n = printf(":%i:", (us)2147483647);		printf("\t\t\t%d\n", n);
	printf("\t17. pf(\":%%i:\", (short)2147483647):\t");	  n = printf(":%i:", (short)2147483647);	printf("\t\t\t%d\n", n);
	printf("\t18. pf(\":%%i:\", (ui)2147483647):\t\t");		  n = printf(":%i:", (ui)2147483647);		printf("\t\t%d\n", n);
	printf("\t19. pf(\":%%i:\", (int)2147483647):\t");		  n = printf(":%i:", (int)2147483647);		printf("\t\t%d\n", n);
	// if we proceed with ul, long, ull, long long the compiler will warn us

	// testing %u
	printf("\nTesting %%u\n");
	printf("\t1.  pf(\":%%u:\", -199):\t\t\t");		n = printf(":%u:", -199);		printf("\t\t%d\n", n);
	printf("\t2.  pf(\":%%u:\", -1):\t\t\t");		n = printf(":%u:", -1);			printf("\t\t%d\n", n);
	printf("\t3.  pf(\":%%u:\", 0):\t\t\t");		n = printf(":%u:", 0);			printf("\t\t\t%d\n", n);
	printf("\t4.  pf(\":%%u:\", 100):\t\t\t");		n = printf(":%u:", 100);		printf("\t\t\t%d\n", n);
	printf("\t5.  pf(\":%%u:\", 65535):\t\t\t");	n = printf(":%u:", 65535);		printf("\t\t\t%d\n", n);
	printf("\t6.  pf(\":%%u:\", 2147483647):\t\t");	n = printf(":%u:", 2147483647);	printf("\t\t%d\n", n);
	printf("\t7.  pf(\":%%u:\", 457):\t\t\t");		n = printf(":%10u:", 457);		printf("\t\t%d\n", n);
	printf("\t8.  pf(\":%%u:\", 457):\t\t\t");		n = printf(":%-10u:", 457);		printf("\t\t%d\n", n);
	printf("\t9.  pf(\":%%u:\", 457):\t\t\t");		n = printf(":%010u:", 457);		printf("\t\t%d\n", n);


	// testing unsigned char with %x
	printf("\nTesting %%x\n");
	printf("\nwidth unsigned char\n");
	printf("\t1.  pf(:\"%%x:\", (uc)-259):\t\t");	n = printf(":%x:", (uc)-259);	printf("\t\t\t%d\n", n);
	printf("\t2.  pf(:\"%%x:\", (uc)-258):\t\t");	n = printf(":%x:", (uc)-258);	printf("\t\t\t%d\n", n);
	printf("\t3.  pf(:\"%%x:\", (uc)-257):\t\t");	n = printf(":%x:", (uc)-257);	printf("\t\t\t%d\n", n);
	printf("\t4.  pf(:\"%%x:\", (uc)-256):\t\t");	n = printf(":%x:", (uc)-256);	printf("\t\t\t%d\n", n);
	printf("\t5.  pf(:\"%%x:\", (uc)-255):\t\t");	n = printf(":%x:", (uc)-255);	printf("\t\t\t%d\n", n);
	printf("\t6.  pf(:\"%%x:\", (uc)-254):\t\t");	n = printf(":%x:", (uc)-254);	printf("\t\t\t%d\n", n);
	printf("\t7.  pf(:\"%%x:\", (uc)-10):\t\t");	n = printf(":%x:", (uc)-10);	printf("\t\t\t%d\n", n);
	printf("\t8.  pf(:\"%%x:\", (uc)-1):\t\t\t");	n = printf(":%x:", (uc)-1);		printf("\t\t\t%d\n", n);
	printf("\t9.  pf(:\"%%x:\", (uc)0):\t\t\t");	n = printf(":%x:", (uc)0);		printf("\t\t\t%d\n", n);
	printf("\t10. pf(:\"%%x:\", (uc)1):\t\t\t");	n = printf(":%x:", (uc)1);		printf("\t\t\t%d\n", n);
	printf("\t11. pf(:\"%%x:\", (uc)10):\t\t\t");	n = printf(":%x:", (uc)10);		printf("\t\t\t%d\n", n);
	printf("\t12. pf(:\"%%x:\", (uc)254):\t\t");	n = printf(":%x:", (uc)254);	printf("\t\t\t%d\n", n);
	printf("\t13. pf(:\"%%x:\", (uc)255):\t\t");	n = printf(":%x:", (uc)255);	printf("\t\t\t%d\n", n);
	printf("\t14. pf(:\"%%x:\", (uc)256):\t\t");	n = printf(":%x:", (uc)256);	printf("\t\t\t%d\n", n);
	printf("\t15. pf(:\"%%x:\", (uc)257):\t\t");	n = printf(":%x:", (uc)257);	printf("\t\t\t%d\n", n);

	// testing signed char with %x
	printf("\nwith signed char\n");
	printf("\t16. pf(:\"%%x:\", (char)-259):\t\t");	n = printf(":%x:", (char)-259);	printf("\t\t%d\n", n);
	printf("\t17. pf(:\"%%x:\", (char)-258):\t\t");	n = printf(":%x:", (char)-258);	printf("\t\t%d\n", n);
	printf("\t18. pf(:\"%%x:\", (char)-257):\t\t");	n = printf(":%x:", (char)-257);	printf("\t\t%d\n", n);
	printf("\t19. pf(:\"%%x:\", (char)-256):\t\t");	n = printf(":%x:", (char)-256);	printf("\t\t\t%d\n", n);
	printf("\t20. pf(:\"%%x:\", (char)-255):\t\t");	n = printf(":%x:", (char)-255);	printf("\t\t\t%d\n", n);
	printf("\t21. pf(:\"%%x:\", (char)-254):\t\t");	n = printf(":%x:", (char)-254);	printf("\t\t\t%d\n", n);
	printf("\t22. pf(:\"%%x:\", (char)-10):\t\t");	n = printf(":%x:", (char)-10);	printf("\t\t%d\n", n);
	printf("\t23. pf(:\"%%x:\", (char)-1):\t\t");	n = printf(":%x:", (char)-1);	printf("\t\t%d\n", n);
	printf("\t24. pf(:\"%%x:\", (char)0):\t\t");	n = printf(":%x:", (char)0);	printf("\t\t\t%d\n", n);
	printf("\t25. pf(:\"%%x:\", (char)1):\t\t");	n = printf(":%x:", (char)1);	printf("\t\t\t%d\n", n);
	printf("\t26. pf(:\"%%x:\", (char)10):\t\t");	n = printf(":%x:", (char)10);	printf("\t\t\t%d\n", n);
	printf("\t27. pf(:\"%%x:\", (char)254):\t\t");	n = printf(":%x:", (char)254);	printf("\t\t%d\n", n);
	printf("\t28. pf(:\"%%x:\", (char)255):\t\t");	n = printf(":%x:", (char)255);	printf("\t\t%d\n", n);
	printf("\t29. pf(:\"%%x:\", (char)256):\t\t");	n = printf(":%x:", (char)256);	printf("\t\t\t%d\n", n);
	printf("\t30. pf(:\"%%x:\", (char)257):\t\t");	n = printf(":%x:", (char)257);	printf("\t\t\t%d\n", n);
	printf("\t31. pf(:\"%%x:\", (char)258):\t\t");	n = printf(":%x:", (char)258);	printf("\t\t\t%d\n", n);
	printf("\t32. pf(:\"%%x:\", (char)259):\t\t");	n = printf(":%x:", (char)259);	printf("\t\t\t%d\n", n);
	
	// testing unsigned short with %x
	printf("\nwith unsigned short\n");
	printf("\t33. pf(:\"%%x:\", (us)0):\t\t\t");	n = printf(":%x:", (us)0);		printf("\t\t\t%d\n", n);
	printf("\t34. pf(:\"%%x:\", (us)1):\t\t\t");	n = printf(":%x:", (us)1);		printf("\t\t\t%d\n", n);
	printf("\t35. pf(:\"%%x:\", (us)1024):\t\t");	n = printf(":%x:", (us)1024);	printf("\t\t\t%d\n", n);
	printf("\t36. pf(:\"%%x:\", (us)65535):\t\t");	n = printf(":%x:", (us)65535);	printf("\t\t\t%d\n", n);
	printf("\t37. pf(:\"%%x:\", (us)65536):\t\t");	n = printf(":%x:", (us)65536);	printf("\t\t\t%d\n", n);
	printf("\t38. pf(:\"%%x:\", (us)65537):\t\t");	n = printf(":%x:", (us)65537);	printf("\t\t\t%d\n", n);

	// testing signed short with %X
	printf("\nwith signed short\n");
	printf("\t38. pf(\":%%X:\", (short)-32769):\t\t");	 n = printf(":%X:", (short)-32769);printf("\t\t\t%d\n", n);
	printf("\t39. pf(\":%%X:\", (short)-32768):\t\t");	 n = printf(":%X:", (short)-32768);printf("\t\t%d\n", n);
	printf("\t40. pf(\":%%X:\", (short)-32767):\t\t");	 n = printf(":%X:", (short)-32767);printf("\t\t%d\n", n);
	printf("\t41. pf(\":%%X:\", (short)-1024):\t\t");	 n = printf(":%X:", (short)-1024); printf("\t\t%d\n", n);
	printf("\t42. pf(\":%%X:\", (short)-100):\t\t");	 n = printf(":%X:", (short)-100);  printf("\t\t%d\n", n);
	printf("\t43. pf(\":%%X:\", (short)-1):\t\t");		 n = printf(":%X:", (short)-1);	   printf("\t\t%d\n", n);
	printf("\t44. pf(\":%%X:\", (short)0):\t\t");		 n = printf(":%X:", (short)0);	   printf("\t\t\t%d\n", n);
	printf("\t45. pf(\":%%X:\", (short)100):\t\t");		 n = printf(":%X:", (short)100);   printf("\t\t\t%d\n", n);
	printf("\t46. pf(\":%%X:\", (short)1024):\t\t");	 n = printf(":%X:", (short)1024);  printf("\t\t\t%d\n", n);
	printf("\t47. pf(\":%%X:\", (short)32767):\t\t");	 n = printf(":%X:", (short)32767); printf("\t\t\t%d\n", n);
	printf("\t48. pf(\":%%X:\", (short)32768):\t\t");	 n = printf(":%X:", (short)32768); printf("\t\t%d\n", n);
	printf("\t49. pf(\":%%X:\", (short)32769):\t\t");	 n = printf(":%X:", (short)32769); printf("\t\t%d\n", n);

	// testing %x with flags and width
	printf("\nwith flags and width\n");
	printf("\t50. pf(\":%%#010x:\", %d):\t\t", hexnum);		n = printf(":%#010x:", hexnum);		printf("\t\t%d\n", n);
    printf("\t51. pf(\":%%#x:\", 0x2a):\\n\"):\t\t");		n = printf(":%#x:", 0x2a);			printf("\t\t\t%d\n", n);
    printf("\t52. pf(\":%%#x:\", 0x00):\t\t\t");			n = printf(":%#x:", 0x00);			printf("\t\t\t%d\n", n);
    printf("\t53. pf(\":%%-10x:\", %d):\t\t", hexnum);		n = printf(":%-10x:", hexnum);		printf("\t\t%d\n", n);
    printf("\t54. pf(\":%%6.2x:\", 0x5fa2):\t\t");			n = printf(":%6.2x:", 0x5fa2);		printf("\t\t%d\n", n);
    printf("\t55. pf(\":%%#-.4x:\", 0x5fa4b):\t\t");		n = printf(":%#-.4x:", 0x5fa4b);	printf("\t\t%d\n", n);
    printf("\t56. pf(\":%%#.8x:\", 0x5fa4b):\t\t");			n = printf(":%#.8x:", 0x5fa4b);		printf("\t\t%d\n", n);
    printf("\t57. pf(\":%%12.8x:\", 0x5fa4b):\t\t");		n = printf(":%12.8x:", 0x5fa4b);	printf("\t\t%d\n", n);

	// too few arguments
	char	*null_ptr = NULL;
	int n = printf("We are %s some %s, and %s (%p) we are very %d happy %d about %f it\n",
		"printing", "data", null_ptr, null_ptr, 3485938);
	printf("n = %d\n", n);

	n = printf("We are %s some %s, and %s (%p) we are very %d happy %d about %f it\n",
		"printing", "data", null_ptr, null_ptr, 3485938, 0, 3.1415926535, "kekek", 1000, 2.719281928459045);
	printf("n = %d\n", n);


/*
 // Testing %n
    int total = printf("let's print the first string: \"%s\"; %n"\
           "let's print the second string: \"%s\";%n\n",
           str, &n1, str1, &n2);
    printf("n1 = %d; n2 = %d; total = %d\n", n1, n2, total);

	// Testing %o
    n = printf("18. pf(\":%%-10o:\\n\"): "); printf(":%-10o:\n", octnum);

	// Testing %f
    printf(":%.*f:\n", prec, fnum1);
    printf(":%*.*f:\n", min_fld_wid, prec, fnum2);
    printf(":% *.*f:\n", min_fld_wid, prec, fnum3);
    printf(":% *.*f:\n", min_fld_wid, prec, fnum3);

    // Testing mixed conversions
    printf(">%1$d:%3$d:%2$s<\n", 1, "abcd", 2);
    printf(">%1$d:%3$*4$d:%2$s<\n", 1, "abcd", 2, min_fld_wid);
    printf(">%1$d:%3$-*4$d:%2$s<\n", 1, "abcd", 2, min_fld_wid);*/

	return 0;
}
