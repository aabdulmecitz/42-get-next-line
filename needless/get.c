/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:10:35 by root              #+#    #+#             */
/*   Updated: 2024/08/23 21:31:20 by kali             ###   ########.fr       */
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

//CALISMALARIMIZI BURADA YAPIYORUZ TEST EDIYORUZ. Çalışırsa Ana projeye ekliyoruz.

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strchr(const char *s, char c)
{
    while (*s)
    {
        if (*s == c)
            return (char *)s;
        s++;
    }
    if (*s == '\0')
        return (char *)s;
    return NULL;
}
//---------------------------------------------------------------------
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
//-------------------------------------------------------------------
char    *ft_strjoin_and_free(char *dst, char *src)
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

char    *ft_strowrite(char *dest, char *src)
{
    int i;

    i = 0;
    free(dest);
    dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
    if (!dest)
        return NULL;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[ft_strlen(src)] = '\0';
    return dest;
}

char    *get_next_line(int fd) {
    /*
    Mallocla açtığımız BUFFER_SIZE lık bolgeyi buf olarak tanımladık. read fonksiyonu ile BUFFER_SIZE kadar olan byte sayısı kadarını 
    okur ve buf a yazılır. buf un sonuna da \0 eklemek gerekiyor ki string olsun. read fonksiyonunu her çalıştırdığımızda
    verdiğimiz size kadarını okuyup sonra kaldığı yerden verdiğimiz byte sayısı kadarını tekrar okuyuyacağından static gibi bir 
    davranış gösteriyor.
    buf a aldığımız buff size byte kadar char verisi içerisinde araştırma yaparız. \n veya \0 var mı yokmu ona bakarız. 
    Eğer null varsa zaten bir problem yok strjoin ile nulla kadar olan kısmı currentStr nin üzerine ekler geçeriz. Sonra onu 
    döndürürüz zaten okuyacağımız stringin sonuna gelmişiz. 
    Eğer null değilde \n ise strcpy ile aldığımız ilk \n ın pointerını aldığımızdan aynı zmanada bize \n den BUFFER_SIZE lın sonuna 
    kadar bir string elde etmis oluyoruz. Bunu da statik olarak tannımladığımız bir char * ına veriyoruz ki bir sonraki çağırıldığında erişelim.
    fonksiyon bir daha çağırıldığında ilk işi strjoin ile static tanımladığımız ve 42 liğin \n sonraki değerini alan lastPartOfBuff üzerinde gezinir.
    \n veya \0 olup olmadığına bakar \0 sa problem yok ve read ile yine okuyabiliriz. Ama \n ise buf a strchr ile yine \n dan sonraki kısmı veririz.
    buff un içerisinde birden fazla \n varsa eğer hepsini eklersek \n olanları da eklemiş oluruz o yüzden lastPartOfBuff un da içerisinde gezinmek gerek.
    eğer içerisinde \n varsa o zaman read yapmamıza yine gerek kalmaz. 
    en başta lastPArtOfBuffer ı kontrol ederiz null değilse içerisinde \n olma ihtimali var eğer varsa oraya kadar bir stringe yazarız,
    geri kalanını da lastPartOfBuff a yazarız. nullsa zaten birşey yapmaya gerek yok. zaten ilk 
    çalıştırdığımızda da lastPartOfBuff null olacağı için problem kalmıyor. 
    
    if (lastPartOfBuff != null)
    {
        while(lastPartOfBuff != \n ){
            str[i] = lastPartOfBuff[i];
            i++;
        }
        str[i] = 0;
        
        lastPartOfBuff = strncpy(buf, \n);
    }
    
    */
    char * currentStr; //döndüreceğimiz ve strjoinle üzerine ekleme yapacağımız string
    static char *lastPartOfBuff; //buff size kadar alanda eğer biz \n bulursak strcpy ile \n in bulunduğu kısımdan sonraki diziyi ifade eder.
    char *totalStr;
    int i;
    char buff[BUFFER_SIZE + 1]; //Her fonksiyon çağırıldığında read fonksiyonu ile okuyacağımız ve geçici olarak üzerine yazacağımız string mallocla açılmalı.
    int a;
    
    currentStr = (char *)malloc(1);
    
    while ((a = read(fd, buff, BUFFER_SIZE)) > 0) 
    {
        buff[a] = '\0'; // null-terminate the buffer
        if (lastPartOfBuff)
        {
            ft_strowrite(currentStr,ft_strBFirstchr(lastPartOfBuff, '\n'));
            if (ft_strlen(currentStr) < ft_strlen(lastPartOfBuff))
            {
                lastPartOfBuff = ft_strAFirstchr(lastPartOfBuff, '\n');
                return (currentStr);
            }
            free(lastPartOfBuff);
            lastPartOfBuff = NULL;
        }
        
        if (ft_strchr(buff, '\n'))
        {
            lastPartOfBuff = ft_strAFirstchr(buff, '\n');
            currentStr = ft_strjoin_and_free(currentStr, buff);
            break;
        }
        currentStr = ft_strjoin_and_free(currentStr,buff);
    }
    
    return currentStr;
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
    // printf("\n------------------------------------\n");
    //     printf("%s", get_next_line(fd));
    // printf("\n------------------------------------\n");
    //     printf("%s", get_next_line(fd));
    // printf("\n------------------------------------\n");
    //     printf("%s", get_next_line(fd));

    return 0;
}
