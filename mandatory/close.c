/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:54:21 by mnahli            #+#    #+#             */
/*   Updated: 2025/04/02 12:09:14 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	total_coins(t_game *game)
{
	int	y;
	int	x;

	game->coins = 0;
	y = -1;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][++x])
			if (game->map[y][x] == 'C')
				game->coins++;
	}
}

void	print_moves(int i)
{
	char	*str;

	str = ft_itoa(i);
	ft_putstr_fd("number of movements: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
}

int	close_win(t_game *game)
{
	free_map(game->map);
	if (game->img_coin)
		mlx_destroy_image(game->mlx, game->img_coin);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}
