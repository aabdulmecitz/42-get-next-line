/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gett.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:05:59 by kali              #+#    #+#             */
/*   Updated: 2024/08/24 21:38:57 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 9999
#endif

int         ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

const char	*ft_strchr(const char *s, int c)
{
	const char	*str;
	str = s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char        *ft_strjoin(char *s1, char *s2)
{
	char	*start;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	start = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (start);
}

char        *ft_strdup(const char *s) 
{
    char *dup;
    size_t len = 0;
    
    while (s[len])
        len++;
    dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup)
        return NULL;
    for (size_t i = 0; i < len; i++) {
        dup[i] = s[i];
    }
    dup[len] = '\0';
    return dup;
}

char *get_next_line(int fd)
{
    static char *buf;
    char temp[BUFFER_SIZE + 1];
    char *newline_pos;
    char *str;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    // Allocate buffer if not already allocated
    if (!buf)
    {
        buf = malloc(1);
        if (!buf)
            return NULL;
        buf[0] = '\0';
    }

    while ((bytes_read = read(fd, temp, BUFFER_SIZE)) > 0)
    {
        temp[bytes_read] = '\0';
        char *new_buf = ft_strjoin(buf, temp);
        free(buf);
        buf = new_buf;

        newline_pos = (char *)ft_strchr(buf, '\n');
        if (newline_pos)
        {
            *newline_pos = '\0';
            str = ft_strdup(buf);
            char *remaining = ft_strdup(newline_pos + 1);
            free(buf);
            buf = remaining;
            return str;
        }
    }

    if (bytes_read < 0 || (bytes_read == 0 && (!buf || *buf == '\0')))
    {
        free(buf);
        buf = NULL;
        return "\n";
    }

    str = ft_strdup(buf);
    free(buf);
    buf = NULL;  
    return str;
}

int main(int argc, char const *argv[])
{
    char    *s1 = "kokokok";
    char    *s2 = "aaaaaa";
    int fd = open("deneme.txt", O_RDWR);

    printf("\n------------------------------------\n");
        printf("%s", get_next_line(fd));
    printf("\n------------------------------------\n");
        printf("%s", get_next_line(fd));
    printf("\n------------------------------------\n");
        printf("%s", get_next_line(fd));
    printf("\n------------------------------------\n");
        printf("%s", get_next_line(fd));
    printf("\n------------------------------------\n");
        printf("%s", get_next_line(fd));
    // printf("\n------------------------------------\n");
    //     printf("%s", get_next_line(fd));
    // printf("\n------------------------------------\n");
    //     printf("%s", get_next_line(fd));
    // printf("\n------------------------------------\n");
    //     printf("%s", get_next_line(fd));
    // printf("\n------------------------------------\n");
    //     printf("%s", get_next_line(fd));
    // printf("\n------------------------------------\n");
    //     printf("%s", get_next_line(fd));
    // printf("\n------------------------------------\n");
    //     printf("%s", get_next_line(fd));
    // printf("\n------------------------------------\n");
    //     printf("%s", get_next_line(fd));
    // printf("\n------------------------------------\n");
    //     printf("%s", get_next_line(fd));
    // printf("\n------------------------------------\n");
    //     printf("%s", get_next_line(fd));

    return 0;
}
