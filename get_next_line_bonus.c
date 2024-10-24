// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line_bonus.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/08/09 02:27:39 by aabdulmecit       #+#    #+#             */
// /*   Updated: 2024/10/24 23:12:29 by aabdulmecit      ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line_bonus.h"

// char	*get_next_line(int fd)
// {
// 	static char	*buf[MAX_FD];
// 	char		*str;
// 	int			bytes_read;

// 	if (!buf[fd])
// 		buf[fd] = ft_strdup("");
// 	bytes_read = 1;
// 	while (bytes_read > 0)
// 	{
// 		buf[fd] = ft_read_and_join(fd, buf[fd], &bytes_read);
// 		if (ft_strchr(buf[fd], '\n'))
// 		{
// 			str = ft_strdup(buf[fd]);
// 			buf[fd] = ft_strdup(ft_strchr(buf[fd], '\n') + 1);
// 			return (ft_strjoin(str, "\n"));
// 		}
// 	}
// 	if (buf[fd] && *buf[fd])
// 	{
// 		str = ft_strdup(buf[fd]);
// 		free(buf[fd]);
// 		buf[fd] = NULL;
// 		return (ft_strjoin(str, "\n"));
// 	}
// 	return ("");
// }
