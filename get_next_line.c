/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/08/19 22:33:05 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>



char    *get_next_line(int fd)
{
    static char * currentStr; //döndüreceğimiz ve strjoinle üzerine ekleme yapacağımız string
    static char *lastPartOfBuff; //buff size kadar alanda eğer biz \n bulursak strcpy ile \n in bulunduğu kısımdan sonraki diziyi ifade eder.
    char *totalStr;
    int i;
    char buff[BUFFER_SIZE + 1]; //Her fonksiyon çağırıldığında read fonksiyonu ile okuyacağımız ve geçici olarak üzerine yazacağımız string mallocla açılmalı.
    int a;
    
    if (lastPartOfBuff != NULL)
    {
        while (*lastPartOfBuff)
        {
            if(*lastPartOfBuff == '\n')
            {
                currentStr = ft_strBFirstchr(lastPartOfBuff, '\n');
                lastPartOfBuff = ft_strAFirstchr(lastPartOfBuff, '\n');
                break;
            }
            lastPartOfBuff++;    
        }
        totalStr = ft_strCombine(currentStr, lastPartOfBuff);
    }
    
    if (!(a = read(fd, buff, BUFFER_SIZE))) //a nın null olup olmadığına bakıyoruz nullsa boşluk döndürüyoruz.
    {
        currentStr[0] = '\0';
        return (NULL);
    }
    if (!currentStr)
    {
        currentStr = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (!currentStr)
            return (NULL);
    }
        
    return totalStr;
}

int main(int argc, char const *argv[])
{
    int fd = open("deneme.txt", O_RDWR);
    get_next_line(fd);    
    return 0;
}
