/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:32:26 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/05 17:29:13 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void upd_key_bool(int keycode, s_game *game, int x)
{
  if (keycode == 119)
    game->key_bool[0] = x;
  if (keycode == 115)
    game->key_bool[1] = x;
  if (keycode == 97)
    game->key_bool[2] = x;
  if (keycode == 100)
    game->key_bool[3] = x;
  if (keycode == 65361)
    game->key_bool[4] = x;
  if (keycode == 65363)
    game->key_bool[5] = x;
}

int ft_release(int keycode, s_game *game)
{
	upd_key_bool(keycode, game, 0);
	return (0);
}

int	ft_button(int keycode, s_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(game->mlx, game->img->img);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		// free_game
		exit(0);
	}
  upd_key_bool(keycode, game, 1);
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		move_player(game, keycode);
	else if (keycode == 65361 || keycode == 65363)
		rotate_camera(game, keycode);
	return (0);
}

int	cross_close(s_game *game)
{
	mlx_destroy_image(game->mlx, game->img->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	// free_game
	exit(0);
	return (0);
}

void	key_controls(s_game *game)
{
	mlx_hook(game->win, 17, 0, cross_close, game);
	mlx_hook(game->win, 2, 1L << 0, ft_button, game);
	mlx_hook(game->win, 2, 1L << 1, ft_release, game);
	// gerer les key en continu
}
