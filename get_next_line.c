/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 19:37:41 by tsehr             #+#    #+#             */
/*   Updated: 2019/06/18 23:56:51 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char	*pool[255];
	int			line_length;
	int			buffer_status;

	if (!pool[fd])
		pool[fd] = ft_strnew(10000000);
	REQUIRE((fd >= 0 && line && pool[fd]));
	line_length = save_line_and_return_index(pool, fd, line);
	if (pool[fd][line_length] == '\0')
	{
		buffer_status = buffer_pool(pool, fd, line_length, 0);
		if (buffer_status == -1)
			return (-1);
		else if (buffer_status == 1 && !pool[fd][1])
			return (0);
		line_length = save_line_and_return_index(pool, fd, line);
		clean_pool(pool, fd, line_length);
		return (1);
	}
	else if (pool[fd][line_length] == '\n')
	{
		clean_pool(pool, fd, line_length);
		return (1);
	}
	return (-1);
}

void	clean_pool(char *pool[255], int fd, int line_end)
{
	int		pool_start;
	int		next_line_start;
	char	*temp;

	next_line_start = line_end + 1;
	temp = ft_strnew(line_end);
	pool_start = 0;
	while (pool[fd][next_line_start])
	{
		temp[pool_start] = pool[fd][next_line_start];
		pool_start++;
		next_line_start++;
	}
	temp[pool_start] = '\0';
	ft_bzero(pool[fd], 10000000);
	pool[fd] = ft_strcpy(pool[fd], temp);
}

int		save_line_and_return_index(char *pool[255], int fd, char **line)
{
	int	line_length;

	line_length = 0;
	while (pool[fd][line_length] != '\n')
	{
		if (pool[fd][line_length] == '\0')
		{
			return (line_length);
		}
		line_length++;
	}
	*line = ft_strnew(line_length + 1);
	*line = ft_strncpy(*line, pool[fd], line_length);
	return (line_length);
}

int		buffer_pool(char *pool[255], int fd, int pool_index, int v_flag)
{
	char	buffer[BUFF_SIZE + 1];
	int		pool_length;
	int		buffer_index;
	int		buffer_length;

	pool_length = ft_strlen(pool[fd]);
	while (!v_flag)
	{
		buffer_index = 0;
		buffer_length = read(fd, buffer, BUFF_SIZE);
		REQUIRE((buffer_length != -1));
		pool_length += buffer_length;
		while (pool_index < pool_length)
		{
			pool[fd][pool_index] = buffer[buffer_index];
			if (buffer[buffer_index] == '\n')
				v_flag = 1;
			pool_index++;
			buffer_index++;
		}
		if (buffer_length == 0)
			return (v_flag = handle_file_end(pool, fd, pool_index));
	}
	pool[fd][pool_index] = '\0';
	return (0);
}

int		handle_file_end(char *pool[255], int fd, int pool_index)
{
	pool[fd][pool_index] = '\n';
	pool_index++;
	pool[fd][pool_index] = '\0';
	return (1);
}

int main(int argc, char **argv)
{
	int fd;
	int ret = 0;
	char *line;
	int i = 0;
	REQUIRE((argc >= 2));

	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		printf("this is my return: [%d]\n", ret);
		printf("and this is my line: %s\n_____________\n", line);
		i++;
	}

	return (0);
}