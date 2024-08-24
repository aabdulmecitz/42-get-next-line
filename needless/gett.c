/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gett.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:05:59 by kali              #+#    #+#             */
/*   Updated: 2024/08/24 17:52:42 by kali             ###   ########.fr       */
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
