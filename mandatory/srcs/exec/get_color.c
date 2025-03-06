/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:56:11 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/06 11:02:16 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
int	get_textures(s_game *game, s_rayon *rayon, int **buffer, int x, int y)
{
	int		texX;
	int		texY;
	int		texNum;	// fonction pour definir si on est N, O, E, S
	double	step;
	double	texPos;

	// fonction texNum
	texNum = 0;
	texX = (int)(wall * (double)texWidth); // /!\ texWidth est une macro (genre 64), voir comment on gere ca pour que les textures donnes soient au bon format
	if (rayon->side == 0 && rayon->dir_x > 0)
		texX = texWidth - texX - 1;
	if (rayon->side == 1 && rayon->dir_y < 0)
		texX = texWidth - texX - 1;
	step = 1.0 * texHeight / rayon->line_height;
	texPos = (rayon->draw_start - WIN_HEIGHT / 2 + rayon->line_height / 2) * step;
	while (y < rayon->draw_end)
	{
		texY = (int)texPos & (texHeight - 1);
		texPos += step;
		buffer[y][x] = game->tex[texNum][texHeight * texY + texX];
		y++;
	}
	return (y - 1);
// definir texHeight (macro)
}
*/

// fonction nulle pour continuer
int	get_textures(s_game *game, s_rayon *rayon, int **buffer, int x, int y)
{
	(void)game;
	while (y < rayon->draw_end)
	{
		buffer[y][x] = 255;
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
