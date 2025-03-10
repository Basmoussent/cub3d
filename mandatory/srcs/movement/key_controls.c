/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:32:26 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/10 15:05:13 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	upd_key_bool(int keycode, t_game *game, int x)
{
	if (keycode == W)
		game->key_bool[0] = x;
	if (keycode == S)
		game->key_bool[1] = x;
	if (keycode == A)
		game->key_bool[2] = x;
	if (keycode == D)
		game->key_bool[3] = x;
	if (keycode == LEFT)
		game->key_bool[4] = x;
	if (keycode == RIGHT)
		game->key_bool[5] = x;
}

int	ft_release(int keycode, t_game *game)
{
	upd_key_bool(keycode, game, 0);
	return (0);
}

int	ft_button(int keycode, t_game *game)
{
	if (keycode == ESC)
		free_all(game, 0);
	upd_key_bool(keycode, game, 1);
	return (0);
}

int	cross_close(t_game *game)
{
	free_all(game, 0);
	return (0);
}

void	key_controls(t_game *game)
{
	mlx_hook(game->win, 17, 0, cross_close, game);
	mlx_hook(game->win, 2, 1L << 0, ft_button, game);
	mlx_hook(game->win, 3, 1L << 1, ft_release, game);
}
