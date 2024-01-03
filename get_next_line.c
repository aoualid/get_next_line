/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:36:17 by aroualid          #+#    #+#             */
/*   Updated: 2024/01/03 17:51:13 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <bits/posix2_lim.h>
#include <sys/types.h>


char	*ft_read(int fd, char *ptr)
{
	int			bytes;
	char		buffer[BUFFER_SIZE + 1];

	bytes = 1;
	if (!ptr)
		ptr = ft_calloc(1, 1);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(ptr);
			return (NULL);
		}
		buffer[bytes] = '\0';
		ptr = ft_strjoin(ptr, buffer);
		if (!ptr)
			return NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ptr);
}

char	*ft_nxt_line(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str || *str == 0)
	{
		free(str);
		return NULL;
	}
	while (str[i] && str[i] != '\n')
		i++;
	ptr = ft_calloc(i + 2, sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		ptr[i++] = '\n';
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_overflow(char *str)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	if (!str || *str == 0)
		return NULL;
	while (str[i] && str[i] != '\n')
		i++;
	len = ft_strlen(str);
	ptr = malloc(len - i + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	free(str);
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_nxt_line(buffer);
	buffer = ft_overflow(line);
	return (line);
}

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

// int main()
// {
// 	int fd = open("gnlTester/files/nl", O_RDONLY);
// 	char *s = get_next_line(fd);
// 	printf("%s\n", s);
// 	s = get_next_line(fd);
// 	printf("%s\n", s);
// }
