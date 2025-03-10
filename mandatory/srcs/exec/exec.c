/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:54 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/10 12:35:10 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	draw_buffer(s_game *game, int **buffer)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(game->img, x, y, buffer[y][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 1, 1);
	return (1);
}

static int	**init_buffer(s_game *game, s_rayon *rayon)
{
	int	**buffer;
	int	x;

	x = 0;
	buffer = ft_calloc(sizeof(int *), WIN_HEIGHT + 1);
	if (!buffer)
		return (free(rayon), free_all(game, 1), NULL);
	while (x < WIN_HEIGHT)
	{
		buffer[x] = ft_calloc(sizeof(int), WIN_WIDTH);
		if (!buffer[x])
			return (free_tab((void **)buffer), free_all(game, 1), NULL);
		x++;
	}
	buffer[x] = NULL;
	return (buffer);
}

int	rendering(s_game *game)
{
	s_rayon	*rayon;
	int		**buffer;
	int		x;

	x = 0;
	rayon = ft_calloc(sizeof(s_rayon), 1);
	if (!rayon)
		return (0);
	buffer = init_buffer(game, rayon);
	while (x < WIN_WIDTH)
	{
		get_rayon_data(game, rayon, x);
		get_color(game, rayon, buffer, x);
		x++;
	}
	draw_buffer(game, buffer);
	return (free_tab((void **)buffer), free(rayon), 1);
}

int	update_game(s_game *game)
{
	if (game->key_bool[0] || game->key_bool[1] || game->key_bool[2]
		|| game->key_bool[3] || game->key_bool[4] || game->key_bool[5])
	{
		move_player(game);
		rotate_camera(game);
		rendering(game);
	}
	return (0);
}

int	execution(s_game *game)
{
	rendering(game);
	key_controls(game);
	mlx_loop_hook(game->mlx, &update_game, game);
	mlx_loop(game->mlx);
	return (1);
}
