/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/10/26 22:28:18 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_get_line(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;	
	return(ft_substr(str, 0, i));
	
	//it works
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
    buf = ft_strdup(buf + strlen(line) + (ft_strchr(buf, '\n') ? 1 : 0));
    free(temp);

    return line;
}
int main(int argc, char const *argv[])
{
	int fd = open("deneme.txt", O_RDONLY);

    char *line = get_next_line(fd);
    printf(GREEN "%s\n" RESET, line);
    close(fd);
    return 0;



	
	// int fd;
    // int read_bytes;
    // char *buf = NULL;
    // char *line = NULL;

    // read_bytes = 1;
    // fd = open("deneme.txt", O_RDONLY);
    // buf = ft_append_to_left_one(fd, buf, &read_bytes);
    // line = ft_get_line(buf);
	
    // printf("buff is |%s\n", buf);
    // printf("line is |%s\n", line);

    // free(buf);
    // close(fd);
    return 0;
}
//get_line function gets a line from the string that we read and joined
//one more strings until function found \n character