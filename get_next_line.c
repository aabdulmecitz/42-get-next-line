/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/08/18 20:45:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>



char    *get_next_line(int fd)
{
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
    static char * currentStr; //döndüreceğimiz ve strjoinle üzerine ekleme yapacağımız string
    static char *lastPartOfBuff; //buff size kadar alanda eğer biz \n bulursak strcpy ile \n in bulunduğu kısımdan sonraki diziyi ifade eder.
    char buff; 
    int i;
    char buf[BUFFER_SIZE + 1]; //Her fonksiyon çağırıldığında read fonksiyonu ile okuyacağımız ve geçici olarak üzerine yazacağımız string mallocla açılmalı.
    int a;
    
    


    
    if (!(a = read(fd, buf, BUFFER_SIZE))) //a nın null olup olmadığına bakıyoruz nullsa boşluk döndürüyoruz.
    {
        currentStr[0] = '\0';
        return (NULL);
    }

    if (!currentStr)
        currentStr = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
        
    i = 0;
    while (i != a)
    {
        if (buf[i] == '\n')
            buf[i];
        
        i++;
    }
    
    return currentStr;
}
int main(int argc, char const *argv[])
{
    int fd = open("deneme.txt", O_RDWR);
    get_next_line(fd);    
    return 0;
}
