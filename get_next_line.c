/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:36:17 by aroualid          #+#    #+#             */
/*   Updated: 2024/01/01 19:21:32 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	int		bytes;
	char	buffer[BUFFER_SIZE + 1];	
	char	*ptr;

	bytes = 1;
	if (!ptr)
		ft_calloc(1, 1);
	while (bytes > 0)
	{	
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			return (NULL);
		}
		buffer[bytes] = 0;
		ptr = ft_strjoin(ptr, buffer);
		if (strchr(buffer, '\n'))
			break ;
	}	
	return (ptr);
}

char	*ft_nxt_line(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ptr = malloc (sizeof(char) * i + 2);
	while (j < i)
	{
		ptr[j] = str[j];
		j++;
	}
	if (ptr[i] == '\n')
		ptr [j++] = '\n';
	ptr [j] = '\0';
	return (ptr);
}

char	*ft_overflow(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*ptr;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ptr = malloc (sizeof(char) * (len - i) + 1);
	while (str[i])
		ptr[j++] = str[i++];
	ptr [j] = '\0';
	return (ptr);
}	


