/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:56:36 by mnahli            #+#    #+#             */
/*   Updated: 2025/04/02 10:55:09 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	handl_mem_all(char **str, char **line)
{
	if (!*str)
		error_dbl_free_exit("invalide map", str, line);
}

static void	extract_map(char **str, int fd)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	while (line)
	{
		if (!*line || *line == '\n')
			error_dbl_free_exit("invalide map", str, &line);
		tmp = *str;
		if (!*str)
		{
			*str = ft_strdup(line);
			handl_mem_all(str, &line);
		}
		else
		{
			*str = ft_strjoin(tmp, line);
			free(tmp);
			if (!*str)
				error_dbl_free_exit("memory allocation faild", str,
					&line);
		}
		free(line);
		line = get_next_line(fd);
	}
}

char	**get_map(char *path)
{
	int		fd;
	char	*str;
	char	**map;

	str = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_n_exit("failed to open the file");
	extract_map(&str, fd);
	close(fd);
	if (!str)
		error_n_exit("map is empty");
	map = ft_split(str, '\n');
	free(str);
	if (!map)
		error_n_exit("invalide map");
	return (map);
}
