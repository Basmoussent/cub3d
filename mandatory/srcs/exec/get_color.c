/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:56:11 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/10 09:07:55 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Pas bon pour l'instant
static t_img	*find_side(s_game *game, s_rayon *rayon)
{
	t_img	*tex;
	
	tex = game->tex->no_t;
	if (rayon->side == 1)
	{
		if (rayon->dir_y > 0)
			tex = game->tex->so_t;
		else
			tex = game->tex->no_t;
	}
	else
	{
		if (rayon->dir_x < 0)
			tex = game->tex->we_t;
		else
			tex = game->tex->ea_t;
	}
	return (tex);
}

int	get_textures(s_game *game, s_rayon *rayon, int **buffer, int x, int y)
{
	int		texX;
	int		texY;
	t_img	*tex_dir;
	double	step;
	double	texPos;

	tex_dir = find_side(game, rayon);
	texX = (int)(rayon->wall_x * (double)tex_dir->width);
	if ((rayon->side == 0 && rayon->dir_x < 0) || (rayon->side == 1 && rayon->dir_y > 0))
    texX = tex_dir->width - texX -1;

  step = 1.0 * tex_dir->height / rayon->line_height;
	texPos = (rayon->draw_start - WIN_HEIGHT / 2 + rayon->line_height / 2) * step;
  y = rayon->draw_start;
  while (y < rayon->draw_end)
	{
		texY = (int)texPos % tex_dir->height;
		texPos += step;
		buffer[y][x] = *(int *)(tex_dir->addr + ((texY * tex_dir->line_length) + texX * (tex_dir->bits_per_pixel / 8)));
		y++;
	}
	return (y - 1);
}

void	get_color(s_game *game, s_rayon *rayon, int **buffer, int x)
{
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < rayon->draw_start)
			buffer[y][x] = game->tex->ceili_t; // couleur plafond
		if (y >= rayon->draw_start && y <= rayon->draw_end)
			y += get_textures(game, rayon, buffer, x, y); // textures murs
		else
			buffer[y][x] = game->tex->floor_t; // couleur sol
		y++;
	}
}
