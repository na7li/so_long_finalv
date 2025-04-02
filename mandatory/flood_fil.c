/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:53:46 by mnahli            #+#    #+#             */
/*   Updated: 2025/04/02 10:55:09 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**ft_cpy_map(char **map)
{
	int		i;
	char	**cpy_map;

	cpy_map = NULL;
	i = 0;
	while (map[i])
		i++;
	cpy_map = malloc(sizeof(char *) * (i + 1));
	if (!cpy_map)
		error_free_exit("map copy failed!", map);
	i = -1;
	while (map[++i])
	{
		cpy_map[i] = ft_strdup(map[i]);
		if (!cpy_map[i])
		{
			free_map(cpy_map);
			error_free_exit("failed copying map!", map);
		}
	}
	cpy_map[i] = NULL;
	return (cpy_map);
}

static void	get_player_pos(char **map, t_map *player)
{
	int	i;
	int	j;

	player->x = -1;
	player->y = -1;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
				return ;
			}
		}
	}
	return ;
}

static int	height_cal(char **cpy_map)
{
	int	i;

	i = 0;
	while (cpy_map[i])
		i++;
	return (i);
}

static int	flood_fil(char **cpy_map, int x, int y, t_map *element)
{
	if (x < 0 || y < 0 || x >= (int)ft_strlen(cpy_map[0])
		|| y >= height_cal(cpy_map) || cpy_map[y][x] == '1'
		|| cpy_map[y][x] == 'v')
		return (0);
	if (cpy_map[y][x] == 'E')
	{
		element->exit_found++;
		cpy_map[y][x] = 'v';
	}
	if (cpy_map[y][x] == 'C')
		element->collec_found++;
	cpy_map[y][x] = 'v';
	flood_fil(cpy_map, x + 1, y, element);
	flood_fil(cpy_map, x - 1, y, element);
	flood_fil(cpy_map, x, y + 1, element);
	flood_fil(cpy_map, x, y - 1, element);
	if (element->collec_found == element->collec && element->exit_found == 1)
		return (1);
	return (0);
}

int	is_reachable(char **map, t_map *element)
{
	char	**cpy_map;
	t_map	player;
	int		reach;

	reach = 0;
	if (!map || !*map)
		return (0);
	cpy_map = NULL;
	get_player_pos(map, &player);
	if (player.x == -1 || player.y == -1)
		error_dbl_free_exit("invalid player position!", map, cpy_map);
	cpy_map = ft_cpy_map(map);
	if (!cpy_map)
		error_free_exit("map copying failed!", map);
	reach = flood_fil(cpy_map, player.x, player.y, element);
	free_map(cpy_map);
	return (reach);
}
