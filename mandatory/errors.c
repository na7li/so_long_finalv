/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:54:29 by mnahli            #+#    #+#             */
/*   Updated: 2025/04/02 10:57:12 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map || !*map)
		return ;
	i = -1;
	while (map[++i])
	{
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
	map = NULL;
}

void	error_n_exit(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	error_free_exit(char *msg, char **address)
{
	if (address && *address)
	{
		free_map(address);
		address = NULL;
	}
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	error_dbl_free_exit(char *msg, char **addss_one, char **addss_two)
{
	if (addss_one && *addss_one)
		free_map(addss_one);
	if (addss_two && *addss_two && addss_two != addss_one)
		free_map(addss_two);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	exit_game(char **map)
{
	free_map(map);
	exit(1);
}
