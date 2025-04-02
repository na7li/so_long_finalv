/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:27:30 by mnahli            #+#    #+#             */
/*   Updated: 2025/04/02 09:45:57 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_rectangular(char **map)
{
	int		i;
	size_t	len;

	if (!map || !*map)
		return (0);
	len = ft_strlen(map[0]);
	i = 0;
	while (map[++i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
	}
	return (1);
}

int	is_closed_by_wall(char **map)
{
	int	i;
	int	j;

	if (!map || !*map)
		return (0);
	j = -1;
	while (map[0][++j])
		if (map[0][j] != '1')
			return (0);
	i = 0;
	while (map[++i])
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
	j = -1;
	i--;
	while (map[i][++j])
		if (map[i][j] != '1')
			return (0);
	if ((++i < 3 || j < 5) && (i < 5 || j < 3))
		return (0);
	return (1);
}

static int	initializer(int *i, t_map *element, char **map)
{
	if (!map || !*map)
		return (0);
	*i = -1;
	element->player = 0;
	element->collec = 0;
	element->exit = 0;
	element->collec_found = 0;
	element->exit_found = 0;
	return (1);
}

void	valid_element_msg(t_map *element, char **map)
{
	if (element->player != 1)
		error_free_exit("The map should have ONE player!", map);
	if (element->collec < 1)
		error_free_exit("The map should have at least one Collectable!", map);
	if (element->exit != 1)
		error_free_exit("The map should have ONE Exit!", map);
	return ;
}

int	is_valid_elements(char **map, t_map *element)
{
	int	i;
	int	j;

	if (!initializer(&i, element, map))
		return (0);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				element->player++;
			else if (map[i][j] == 'E')
				element->exit++;
			else if (map[i][j] == 'C')
				element->collec++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				error_free_exit("Unknown element", map);
		}
	}
	if (element->player != 1 || element->exit != 1 || element->collec < 1)
		valid_element_msg(element, map);
	return (1);
}
