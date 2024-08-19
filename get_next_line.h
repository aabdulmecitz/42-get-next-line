/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:46 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/08/19 22:01:32 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//--------------------------------------------------------------------------------
char    *ft_strAFirstchr(char *str, int c);
char    *ft_strBFirstchr(char *str, char c);
char    *get_next_line(int fd);
char    *ft_strCombine(char *dst, char *src);
char    *ft_strchr(char *str, int c);

int     ft_strlen(char *s);




#endif