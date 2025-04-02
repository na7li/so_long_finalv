/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:04:31 by mnahli            #+#    #+#             */
/*   Updated: 2025/04/02 10:55:09 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_path(char *str)
{
	int	i;
	int	point;

	if (!str)
		return (0);
	i = -1;
	point = 0;
	while (str[++i])
		if (str[i] == '.')
			point++;
	if (point != 1 || i < 5)
		return (0);
	i--;
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b'
		&& str[i - 3] == '.' && str[i - 4] != '/')
		return (1);
	return (0);
}

int	validate_map(char *path, t_game	*game)
{
	t_map	element;

	if (!check_path(path))
		error_n_exit("invalid path. Make sure it's a <.ber> extension");
	game->map = get_map(path);
	if (!game->map)
		error_n_exit("failed to load the map");
	if (!is_rectangular(game->map))
		error_free_exit("map is not rectangular", game->map);
	if (!is_closed_by_wall(game->map))
		error_free_exit("map is not closed by wall", game->map);
	if (!is_valid_elements(game->map, &element))
		error_free_exit("invalide elements", game->map);
	if (!is_reachable(game->map, &element))
		error_free_exit("unreachable elements", game->map);
	return (1);
}
