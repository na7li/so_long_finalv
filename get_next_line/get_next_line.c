/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:45:19 by mnahli            #+#    #+#             */
/*   Updated: 2025/02/16 12:22:53 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_newline(char *rest)
{
	int	i;

	i = 0;
	while (rest && rest[i])
	{
		if (rest[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_read(int fd, char *rest)
{
	char	*buffer;
	int		nread;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(rest), rest = NULL, NULL);
	nread = 1;
	while (nread > 0)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		buffer[nread] = '\0';
		temp = rest;
		rest = gnl_strjoin(temp, buffer);
		free(temp);
		if (!rest)
			return (free(buffer), buffer = NULL, NULL);
		temp = NULL;
		if (ft_find_newline(rest) >= 0)
			break ;
	}
	free(buffer);
	return (rest);
}

char	*ft_extract_line(char **rest)
{
	int		n;
	int		i;
	char	*line;

	n = ft_find_newline(*rest);
	if (n < 0)
		return (gnl_strdup(*rest));
	line = malloc(n + 2);
	if (!line)
		return (free(*rest), *rest = NULL, NULL);
	i = 0;
	while (i <= n)
	{
		line[i] = (*rest)[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update_rest(char **rest)
{
	int		n;
	char	*uprest;

	n = ft_find_newline(*rest);
	if (n == -1)
		return (free(*rest), *rest = NULL, NULL);
	uprest = gnl_strdup(*rest + n + 1);
	if (!uprest)
		return (free(*rest), *rest = NULL, NULL);
	free(*rest);
	*rest = NULL;
	return (uprest);
}

char	*get_next_line(int fd)
{
	static char		*rest;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(rest), rest = NULL, NULL);
	rest = ft_read(fd, rest);
	if (!rest || *rest == '\0')
		return (free(rest), rest = NULL, NULL);
	line = ft_extract_line(&rest);
	rest = ft_update_rest(&rest);
	return (line);
}
