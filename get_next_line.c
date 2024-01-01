/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:36:17 by aroualid          #+#    #+#             */
/*   Updated: 2024/01/01 19:02:59 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
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

