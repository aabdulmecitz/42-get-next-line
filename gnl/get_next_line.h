/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:52:01 by aozkaya           #+#    #+#             */
/*   Updated: 2024/10/31 14:19:51 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9

#   define RED "\033[31m"
#   define GREEN "\033[32m"
#   define YELLOW "\033[33m"
#   define BLUE "\033[34m"
#   define RESET "\033[0m"

# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int			ft_strlen(const char *s);
const char	*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s);
char        *ft_substr(const char *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
char	    *ft_append_to_left_one(int fd, char *buf);

#endif
