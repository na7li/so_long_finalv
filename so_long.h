/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:44:41 by mnahli            #+#    #+#             */
/*   Updated: 2025/04/02 11:33:40 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0
# define ESC 53

typedef struct s_map
{
	int		player;
	int		collec;
	int		exit;
	int		collec_found;
	int		exit_found;
	int		x;
	int		y;
}			t_map;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img_floor;
	void	*img_coin;
	void	*img_exit;
	void	*img_player;
	void	*img_wall;
	int		x;
	int		y;
	int		ply_x;
	int		ply_y;
	int		coins;
	int		movements;
}			t_game;

void		error_n_exit(char *msg);
void		error_free_exit(char *msg, char **address);
void		error_dbl_free_exit(char *msg, char **addss_one, char **addss_two);
void		free_map(char **map);
void		exit_game(char **map);
int			close_win(t_game *game);
void		print_moves(int i);
void		total_coins(t_game *game);

int			validate_map(char *path, t_game *game);
char		**get_map(char *path);
int			is_rectangular(char **map);
int			is_closed_by_wall(char **map);
int			is_valid_elements(char **map, t_map *element);
int			is_reachable(char **map, t_map *element);

void		lunch_game(t_game *game);
int			key_hook(int keycode, t_game *game);
void		img_to_win(t_game *game);

#endif