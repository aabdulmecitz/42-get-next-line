/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/10/27 13:09:34 by aabdulmecit      ###   ########.fr       */
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

char	*ft_append_to_left_one(int fd, char *buf)
{
	char	temp[BUFFER_SIZE + 1];
    int     read_bytes;

    if (!buf)
		buf = ft_strdup("");
    read_bytes = 1;
	while (!ft_strchr(buf, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, temp, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		temp[read_bytes] = '\0';
		buf = ft_strjoin(buf, temp);
       
	}
	return (buf);
}
char *ft_after_newline(char *input_str) 
{
    char *start;
    char *result;
	size_t result_size;
    
	start = input_str;
    while (*input_str && *input_str != '\n')
        input_str++;
    if (!*input_str) 
	{
        free(start);
        return (NULL);
    }
	input_str++;
	result_size = ft_strlen(input_str);
    result = (char *)malloc(sizeof(char) * (result_size + 1));
    if (!result)
        return (NULL);
    while (*input_str)
        *result++ = *input_str++;
    *result = '\0';
    free(start);
	result -= result_size;
    return (result);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_append_to_left_one(fd, buf);
	if (!buf || !*buf)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	line = ft_get_line(buf);
    buf = ft_after_newline(buf);

	return (line);
}
