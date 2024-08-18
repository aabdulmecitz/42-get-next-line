/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:10:35 by root              #+#    #+#             */
/*   Updated: 2024/08/18 19:40:47 by root             ###   ########.fr       */
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
    static char *buffer;
    static int buffer_size;
    char *line;
    int i, j, len;



    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    if (!buffer) {
        buffer = (char *)malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return NULL;
        buffer_size = BUFFER_SIZE;
    }

    i = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0')
        i++;

    if (buffer[i] == '\n') {
        line = (char *)malloc(i + 1);
        if (!line)
            return NULL;
        strncpy(line, buffer, i);
        line[i] = '\0';
        len = strlen(buffer + i + 1);
        memmove(buffer, buffer + i + 1, len + 1);
        buffer_size -= i + 1;
    } else {
        len = read(fd, buffer + i, BUFFER_SIZE - i);
        if (len == -1)
            return NULL;
        if (len == 0) {
            if (i == 0)
                return NULL;
            line = (char *)malloc(i + 1);
            if (!line)
                return NULL;
            strncpy(line, buffer, i);
            line[i] = '\0';
            free(buffer);
            buffer = NULL;
            buffer_size = 0;
        } else {
            buffer[i + len] = '\0';
            return get_next_line(fd);
        }
    }

    return line;
}


int main(int argc, char const *argv[])
{
    int fd = open("deneme.txt", O_RDWR);
    char *str;

    str = (char *)malloc((BUFFER_SIZE + 1)*sizeof(char));
    if (!str)
        return 0;
    
    read(fd, str, BUFFER_SIZE);
    
    // printf("%s", get_next_line(fd));
    
    // printf("%s", get_next_line(fd));

    // printf("%s", get_next_line(fd));

    // printf("%s", get_next_line(fd));

    printf("STR: %s\n------------------------\n", str);

    read(fd, str, BUFFER_SIZE);

    printf("STR: %s\n------------------------\n", str);

    return 0;
}
