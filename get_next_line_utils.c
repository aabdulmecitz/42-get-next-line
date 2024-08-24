/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:31 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/08/24 19:01:22 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int         ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

const char	*ft_strchr(const char *s, int c)
{
	const char	*str;
    // str[0] = 1;
	str = s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char        *ft_strjoin(char *s1, char *s2)
{
	char	*start;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	start = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (start);
}

char        *ft_strdup(const char *s) 
{
    char *dup;
    size_t len = 0;
    
    // Calculate the length of the string
    while (s[len])
        len++;
    
    // Allocate memory for the duplicate string (+1 for the null terminator)
    dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup)
        return NULL; // Allocation failed
    
    // Copy the string
    for (size_t i = 0; i < len; i++) {
        dup[i] = s[i];
    }
    
    // Null-terminate the duplicate string
    dup[len] = '\0';
    
    return dup;
}
