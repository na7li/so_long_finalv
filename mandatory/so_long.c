/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:44:38 by mnahli            #+#    #+#             */
/*   Updated: 2025/04/02 12:28:16 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error_n_exit("please enter one valid path");
	if (!validate_map(av[1], &game))
		error_n_exit("parsing issue");
	lunch_game(&game);
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, close_win, &game);
	mlx_loop(game.mlx);
	return (0);
}
