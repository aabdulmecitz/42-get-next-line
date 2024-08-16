/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/08/16 11:54:12 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *get_next_line(int fd)
{
    char *str;
    
    str = (char *)malloc(4*sizeof(char));
    while()
    read(fd, str, 4);
    return str;
}
int main(int argc, char const *argv[])
{
    int fd = open("deneme.txt", O_WRONLY || O_CREAT);
    
    printf("%s", get_next_line(fd));
    return 0;
}
