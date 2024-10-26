/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:54:06 by aozkaya           #+#    #+#             */
/*   Updated: 2024/10/26 22:28:53 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
    int fd = open("deneme.txt", O_RDWR);
    printf(GREEN"%s"RESET, get_next_line(fd));
    return 0;
}
