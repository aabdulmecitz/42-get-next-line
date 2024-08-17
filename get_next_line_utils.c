/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:31 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/08/17 21:11:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     ft_strlen(char *s)

{
    int i;

    i = 0;
    while (!s[i])
        i++;
    return (i);
}

char    *ft_strchr(char *str, int c)
{
    int i;

    if(!str)
        return (NULL);
    i = 0;
    
    return (NULL);
}
char    *ft_strcut(char *str)
{
    int size;
    int i;
    char *cut;
    
    i = 0;
    size = ft_strlen (str);
    while (str[i] != 0 && str[i] != '\n')
    {
        cut[i] = str[i];
        i++;
    }
    return (cut);
}

