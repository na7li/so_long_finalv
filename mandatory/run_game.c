/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:45:02 by mnahli            #+#    #+#             */
/*   Updated: 2025/04/02 10:42:25 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_pos(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				game->ply_x = x;
				game->ply_y = y;
				return ;
			}
		}
	}
}

void	next_move(int keycode, int *x, int *y)
{
	if (keycode == KEY_W)
		*y -= 1;
	else if (keycode == KEY_S)
		*y += 1;
	else if (keycode == KEY_D)
		*x += 1;
	else if (keycode == KEY_A)
		*x -= 1;
}

void	execute_move(t_game *game, int nx_x, int nx_y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_floor,
		game->ply_x * 50, game->ply_y * 50);
	game->ply_x = nx_x;
	game->ply_y = nx_y;
	game->map[game->ply_y][game->ply_x] = 'P';
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_player,
		game->ply_x * 50, game->ply_y * 50);
	print_moves(++game->movements);
}

void	move_player(t_game *game, int keycode)
{
	int	nx_x;
	int	nx_y;

	nx_x = game->ply_x;
	nx_y = game->ply_y;
	next_move(keycode, &nx_x, &nx_y);
	if (game->map[nx_y][nx_x] == '1' || (game->map[nx_y][nx_x] == 'E'
			&& game->coins > 0))
		return ;
	else if (game->map[nx_y][nx_x] == 'E' && game->coins == 0)
		close_win(game);
	game->map[game->ply_y][game->ply_x] = '0';
	if (game->map[nx_y][nx_x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_floor, nx_x
			* 50, nx_y * 50);
		game->coins--;
	}
	execute_move(game, nx_x, nx_y);
}

int	key_hook(int keycode, t_game *game)
{
	player_pos(game);
	total_coins(game);
	if (keycode == ESC)
		close_win(game);
	else if (keycode == KEY_W)
		move_player(game, KEY_W);
	else if (keycode == KEY_S)
		move_player(game, KEY_S);
	else if (keycode == KEY_D)
		move_player(game, KEY_D);
	else if (keycode == KEY_A)
		move_player(game, KEY_A);
	return (0);
}
