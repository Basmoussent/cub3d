/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:54 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/12 12:57:00 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	draw_buffer(t_game *game, int **buffer)
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

static int	**init_buffer(t_game *game, t_rayon *rayon)
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
		{
			free_tab((void **)buffer);
			return (free(rayon), free_all(game, 1), NULL);
		}
		x++;
	}
	buffer[x] = NULL;
	return (buffer);
}

int	rendering(t_game *game)
{
	t_rayon	*rayon;
	int		**buffer;
	int		x;

	x = 0;
	rayon = ft_calloc(sizeof(t_rayon), 1);
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
	print_minimap(game);
	return (free_tab((void **)buffer), free(rayon), 1);
}

static void update_cloud(t_game *game)
{
	if (!game->cloud->is_active)
		return;
	game->cloud->x_pos += game->cloud->speed;
	if (game->cloud->x_pos > WIN_WIDTH)
	{
		game->cloud->is_active = 0;
		game->cloud->x_pos = -game->cloud->img->width;
	}
	
	rendering(game);
}

int update_game(t_game *game)
{
	update_doors(game);
	if (game->key_bool[0] || game->key_bool[1] || game->key_bool[2]
		|| game->key_bool[3] || game->key_bool[4] || game->key_bool[5]
		|| game->cloud->is_active)
	{
		move_player(game);
		rotate_camera(game);
		update_cloud(game);
		rendering(game);
	}
	return (0);
}

static void init_cloud(t_game *game)
{
	game->cloud = ft_calloc(1, sizeof(t_cloud));
	if (!game->cloud)
		free_all(game, 1);
	game->cloud->img = malloc(sizeof(t_img));
	if (!game->cloud->img)
	{
		free(game->cloud);
		free_all(game, 1);
	}
	game->cloud->img->img = mlx_xpm_file_to_image(game->mlx, "assets/cloud.xpm",
		&game->cloud->img->width, &game->cloud->img->height);
	if (!game->cloud->img->img)
	{
		free(game->cloud->img);
		free(game->cloud);
		free_all(game, 1);
	}
	game->cloud->img->addr = mlx_get_data_addr(game->cloud->img->img,
		&game->cloud->img->bits_per_pixel, &game->cloud->img->line_length,
		&game->cloud->img->endian);
	game->cloud->is_active = 0;
	game->cloud->speed = 2.0;
}

int execution(t_game *game)
{
	init_doors(game);
	init_minimap(game);
	init_cloud(game);
	rendering(game);
	key_controls(game);
	mlx_loop_hook(game->mlx, &update_game, game);
	mlx_loop(game->mlx);
	return (1);
}
