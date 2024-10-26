/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:27:39 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/10/26 06:44:39 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*str;
	int			bytes_read;

	if (!buf)
		buf = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		buf = ft_read_and_join(fd, buf, &bytes_read);
		if (ft_strchr(buf, '\n'))
		{
			str = ft_strdup(buf);
			buf = ft_strdup(ft_strchr(buf, '\n') + 1);
			return (ft_strjoin(str, "\n"));
		}
	}
	if (buf && *buf)
	{
		str = ft_strdup(buf);
		free(buf);
		buf = NULL;
		return (ft_strjoin(str, "\n"));
	}
	return ("");
}
