#include "libft/libft.h"

char	*reverse_str(char *str)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < (strlen(str) >> 1))
	{
	    tmp = str[i];
		str[i] = str[strlen(str) - i - 1];
		str[strlen(str) - i - 1] = tmp;
		i++;
	}
	return (str);
}

char	*int_to_hex(unsigned int num, int dcase)
{
	char	*lower;
	char	*upper;
	char	*str;
	int		i;

	lower = "0123456789abcdef\0";
	upper = "0123456789ABCDEF\0";
	str = calloc(16, sizeof (char));
	if (str == NULL)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	i = 0;
	while (num != 0)
	{
		if (dcase == LOWERCASE)
			str[i] = lower[num % 16];
		else if (dcase == UPPERCASE)
			str[i] = upper[num % 16];
		num /= 16;
		i++;
	}
	return (reverse_str(str));
}
