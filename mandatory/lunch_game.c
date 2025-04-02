/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:57:19 by mnahli            #+#    #+#             */
/*   Updated: 2025/04/02 10:55:09 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_to_win(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_floor, x
				* 50, y * 50);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_wall, x * 50, y * 50);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_coin, x * 50, y * 50);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_player, x * 50, y * 50);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_exit, x * 50, y * 50);
		}
	}
}

void	img_init(t_game *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&width, &height);
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm",
			&width, &height);
	game->movements = 0;
	if (!game->img_wall || !game->img_coin || !game->img_exit
		|| !game->img_floor || !game->img_player)
		error_free_exit("failed to load image!", game->map);
}

void	lunch_game(t_game *game)
{
	int	x;
	int	y;

	x = ft_strlen(game->map[0]);
	y = 0;
	while (game->map[y])
		y++;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_free_exit("failed to init mlx!", game->map);
	game->mlx_win = mlx_new_window(game->mlx, (x * 50), (y * 50), "so_long");
	if (!game->mlx_win)
		error_free_exit("failed to open win!", game->map);
	img_init(game);
	img_to_win(game);
}
