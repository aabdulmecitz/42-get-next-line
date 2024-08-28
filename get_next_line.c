/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/08/28 19:11:23 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd) 
{
    static char *buf = NULL;
    char temp[BUFFER_SIZE + 1];
    char *newline_pos;
    char *str = NULL;
    int a;
    
    if (!buf) 
    {
        buf = malloc(BUFFER_SIZE + 1);
        if (!buf)
            return (NULL); // Allocation failed
        buf[0] = '\0';
    }
    
    while ((a = read(fd, temp, BUFFER_SIZE)) > 0) 
    {
        temp[a] = '\0';
        buf = ft_strjoin(buf, temp);
        newline_pos = (char *)ft_strchr(buf, '\n');
        if (newline_pos) 
        {
            *newline_pos = '\0';
            str = ft_strdup(buf);
            buf = ft_strdup(newline_pos + 1);
            return ft_strjoin(str, "\n");
        }
    }
    
    // If we exit the loop without finding a newline
    if (buf && *buf) {
        str = ft_strdup(buf);
        free(buf);
        buf = NULL;
        return ft_strjoin(str, "\n");
    }
    
    free(buf);
    buf = NULL;
    return "\0";
}
