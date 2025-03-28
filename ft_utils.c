/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 04:54:19 by dchernik          #+#    #+#             */
/*   Updated: 2025/03/28 11:49:07 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*buf;

	buf = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		buf[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	tsize;
	size_t	size_max;

	size_max = (size_t)-1;
	ptr = NULL;
	if ((nmemb == 0) || (size == 0))
	{
		ptr = (void *)malloc(1);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if (nmemb > size_max / size)
		return (NULL);
	tsize = nmemb * size;
	ptr = (void *)malloc(tsize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, tsize);
	return (ptr);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

void	ft_putstr_fd(char *s, int fd)
{
	int	slen;

	slen = ft_strlen(s);
	write(fd, s, slen);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
