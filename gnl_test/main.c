/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:54:06 by aozkaya           #+#    #+#             */
/*   Updated: 2024/10/31 13:15:39 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
	char	*line;
	int		fd1;

	fd1 = open("./deneme.txt", O_RDONLY);

    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);


	
	// int fd;
    // int read_bytes;
    // char *buf = NULL;
    // char *line = NULL;

    // read_bytes = 1;
    // fd = open("deneme.txt", O_RDONLY);
    // buf = ft_append_to_left_one(fd, buf, &read_bytes);
    // line = ft_get_line(buf);
	
    // printf("buff is |%s\n", buf);
    // printf("line is |%s\n", line);

    // free(buf);
    // close(fd);
    return 0;
}
//get_line function gets a line from the string that we read and joined
//one more strings until function found \n character


//PROJ=./gnl docker compose -f ./compose.yml run francinette

//valgrind --show-leak-kinds=all --track-origins=yes --leak-check=full ./gnl.out