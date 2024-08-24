/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:46 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/08/24 19:46:55 by kali             ###   ########.fr       */
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

int         ft_strlen(const char *s);
const char  *ft_strchr(const char *s, int c);
char        *get_next_line(int fd);
char        *ft_strjoin(char *s1, char *s2);
char        *ft_strdup(const char *s);

#endif