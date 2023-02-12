/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:39:55 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/12 20:40:30 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "./gnl/get_next_line.h"

void	free_map(char **map)
{
	int32_t	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

static int32_t	count_lines(char *path)
{
	int32_t	fd;
	int32_t	line;
	int32_t	readc;
	char	buf;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	readc = 1;
	line = 0;
	while (readc)
	{
		readc = read(fd, &buf, 1);
		if (buf == '\n')
			++line;
	}
	close(fd);
	return (line);
}

char	**parse(char *path)
{
	char	**map;
	int32_t	i;
	int32_t	line;
	int32_t	fd;

	line = count_lines(path);
	if (!line)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (line + 1));
	if (!map)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = -1;
	while (++i < line)
		map[i] = get_next_line(fd);
	close(fd);
	return (map);
}
