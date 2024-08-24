/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gett.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:05:59 by kali              #+#    #+#             */
/*   Updated: 2024/08/24 17:19:16 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

int	ft_strlen(const char *s)
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
    // str[0] = 1;
	str = s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
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

char    *ft_strBFirstchr(char *str, char c)
{
    int i;
    char *s;

    i = 0;
    while (str[i] && str[i] != c)
        i++;
    s = (char *)malloc((i + 1)*sizeof(char));
    if (!s)
        return (NULL);
    s[i] = '\0';
    while (i > 0)
    {
        i--;
        s[i] = str[i];
    }
    return (s);    
}

void    ft_stroverwrite(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    while (dest[i])
    {
        dest[i] = '\0';
        i++;
    }
}

char *ft_strdup(const char *s) {
    char *dup;
    size_t len = 0;
    
    // Calculate the length of the string
    while (s[len])
        len++;
    
    // Allocate memory for the duplicate string (+1 for the null terminator)
    dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup)
        return NULL; // Allocation failed
    
    // Copy the string
    for (size_t i = 0; i < len; i++) {
        dup[i] = s[i];
    }
    
    // Null-terminate the duplicate string
    dup[len] = '\0';
    
    return dup;
}

void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = '\0';
}

char *get_next_line(int fd) {
    static char *buf = NULL;
    char temp[BUFFER_SIZE + 1];
    char *newline_pos;
    char *str = NULL;
    int a;
    
    if (!buf) {
        buf = malloc(BUFFER_SIZE + 1);
        if (!buf)
            return (NULL); // Allocation failed
        buf[0] = '\0';
    }
    
    while ((a = read(fd, temp, BUFFER_SIZE)) > 0) {
        temp[a] = '\0';
        buf = ft_strjoin(buf, temp);
        newline_pos = (char *)ft_strchr(buf, '\n');
        if (newline_pos) {
            *newline_pos = '\0';
            str = ft_strdup(buf);
            buf = ft_strdup(newline_pos + 1);
            return str;
        }
    }
    
    // If we exit the loop without finding a newline
    if (buf && *buf) {
        str = ft_strdup(buf);
        free(buf);
        buf = NULL;
        return str;
    }
    
    free(buf);
    buf = NULL;
    return NULL;
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
