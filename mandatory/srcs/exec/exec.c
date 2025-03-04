/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:54 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/04 18:11:11 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h" // a changer

void	draw_wall(s_game *game, s_rayon *rayon, int x)
{
	int	y;
	int	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < rayon->draw_start)
			color = // couleur plafond
		if (y >= rayon->draw_start && y <= rayon->draw_end)
			color = // couleur mur, implementer textures;
		else
			color = // couleur sol
		my_mlx_pixel_put(game->img, x, y, color);
		y++;
	}
}

int	rendering(s_game *game)
{
	int	x;
	s_rayon	*rayon;

	x = 0;
	while (x < WIN_WIDTH) // ou WIDTH
	{
		get_rayon_data(game, rayon, x);
		draw_wall(game, rayon, x); // fonction test, mur bleu, reste noir
		// fonction dessiner floor, ceiling et wall
		x++;
	}
}

int	execution(s_game *game)
{
	if (!init_graphical(game->mlx, game->win, game->img))
		return (0);
	rendering(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 1, 1);
	key_controls()  // a faire
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
