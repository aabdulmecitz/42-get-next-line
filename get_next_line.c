/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/08/16 15:45:48 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char    *get_next_line(int fd)
{
    char *str;
    
    printf("%s", "-----------\n");

    str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));

    
    printf("%s", "-------0----\n");

    read(fd, str, BUFFER_SIZE);
    return str;
}
int main(int argc, char const *argv[])
{
    // int fd = open("deneme.txt", O_RDWR);

    
    
    printf("%s", get_next_line(0));
    fprintf(stderr, "ddbgngnjhgjghgh");
    return 0;
}
