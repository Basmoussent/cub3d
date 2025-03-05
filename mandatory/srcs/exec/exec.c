/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:54 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/05 11:03:10 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rendering(s_game *game)
{
	int	x;
	s_rayon	*rayon;
	int	**buffer;

	x = 0;
	rayon = ft_calloc(sizeof(s_rayon *), 1);
	if (!rayon)
		return (0);
	buffer = ft_calloc(sizeof(int *), WIN_HEIGHT);
	if (!buffer)
		return (free(rayon), 0);
	while (x < WIN_HEIGHT)
	{
		buffer[x] = ft_calloc(sizeof(int), WIN_WIDTH);
	//	if (!buffer[x])
			// return free
		x++;
	}
	x = 0;
	while (x < WIN_WIDTH)
	{
		get_rayon_data(game, rayon, x);
		get_color(game, rayon, buffer, x);
		x++;
	}
//	draw_buffer(game, buffer);
	free(rayon);
	return (1);
}

int	execution(s_game *game)
{
	if (!init_graphical(game->mlx, game->win, game->img))
		return (0);
	rendering(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 1, 1);
//	key_controls()  // a faire
	mlx_loop(game->mlx);
	return (1);
}


/*
int	main()
{
	s_game	*game;
	game->mlx = NULL;
	game->win = NULL;
	game->map = { 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1};
	game->player->px = 3;
	game->player->py = 3;
	game->player->pdx = 1;
	game->player->pdy = 0;
	game->player->plane_x = 0;
	game->player->plane_y = 0.66;
	game->tex = NULL;
	game->img = NULL;

	execution(game);
	return (0);
}
*/
