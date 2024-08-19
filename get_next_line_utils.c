/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:31 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/08/19 21:59:01 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strAFirstchr(char *str, int c)
{
    int i;
    int j;
    char *s;

    i = 0;
    while (str[i])
    {
        if (str[i] == (char)c)
            break;
        i++;
    }
    i++;
    j = 0;
    while (str[i + j])
        j++;
    s = (char *)malloc((j + 1) * (sizeof(char)));
    if (!s)
        return (NULL);
    while (j > 0)
    {
        j--;
        s[j] = str[i + j];
    }
    
    return (s);
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

char    *ft_strCombine(char *dst, char *src)
{
    //this function adds src on dest and returns an char *
    int i;
    int j;
    char *totalStr;
    
    totalStr = (char *)malloc((ft_strlen(dst) + ft_strlen(src) + 1)*sizeof(char));
    if (!totalStr)
        return (NULL);
    
    i = 0;
    while(dst[i])
    {
        totalStr[i] = dst[i];
        i++;
    }
    j = 0;
    while (src[j])
    {
        totalStr[i + j] = src[j];
        j++;
    }
    totalStr[i + j] = '\0';  
    
    return (totalStr);
}

