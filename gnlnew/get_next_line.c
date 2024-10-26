/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/10/27 00:13:51 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;	
	return(ft_substr(str, 0, i));
	
}

char	*ft_append_to_left_one(int fd, char *buf, int *read_bytes)
{
	char	temp[BUFFER_SIZE + 1];

	if (!buf)
        buf = ft_strdup("");
	while (read_bytes > 0)
	{
		*read_bytes += read(fd, temp, BUFFER_SIZE);
		if (*read_bytes < 0)
			return (NULL);
		temp[*read_bytes] = '\0';
		buf = ft_strjoin(buf, temp);
		if (ft_strchr(buf, '\n'))
			break;
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			read_bytes;

	read_bytes = 1;
	buf = ft_append_to_left_one(fd, buf, &read_bytes);
    if (!buf)
        return NULL;

    line = ft_get_line(buf);
    if (!line)
        return NULL;
    char *temp = buf;
    buf = ft_strdup(buf + ft_strlen(line) + (ft_strchr(buf, '\n') ? 1 : 0));
    free(temp);

    return line;
}
