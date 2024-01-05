/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:36:14 by aroualid          #+#    #+#             */
/*   Updated: 2024/01/05 14:41:56 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*(p++) = 0;
		n--;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc (0));
	if (SIZE_MAX / nmemb < size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != (char) c)
	{
		if (*ptr == '\0')
		{
			return (NULL);
		}
		ptr++;
	}
	return (ptr);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ds;
	const char	*sc;
	size_t		i;

	ds = (char *)dest;
	sc = src;
	i = 0;
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			ds[n] = sc[n];
		}
	}
	else
	{
		while (i < n)
		{
			ds[i] = sc[i];
			i++;
		}
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ds;
	size_t	i;

	ds = (char *)dest;
	i = 0;
	while (i < n)
	{
		*(char *)ds = *(char *)src;
		ds++;
		src++;
		i++;
	}
	return (dest);
}
