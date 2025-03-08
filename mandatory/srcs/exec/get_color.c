/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:56:11 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/07 12:06:59 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
int	get_textures(s_game *game, s_rayon *rayon, int **buffer, int x, int y)
{
	int		texX;
	int		texY;
	t_img	tex_dir;	// fonction pour definir si on est N, O, E, S
	double	step;
	double	texPos;

	// fonction texNum
	tex_dir.img = game->tex->no_t->img;
	if (rayon->side == 1)
		tex_dir.img = game->tex->we_t->img;
	tex_dir.addr = mlx_get_data_addr(tex_dir.img, &tex_dir.bits_per_pixel, &tex_dir.line_length, &tex_dir.endian);
	// ici au hasard, a bien coder

	printf("Img : img = %p, addr = %s, bits = %d\n", game->tex->no_t->img, game->tex->no_t->addr, game->tex->no_t->bits_per_pixel);
	fflush(stdout);
	printf("Img : line lenght = %d, endian = %d, width = %d, height = %d\n", game->tex->no_t->line_length, game->tex->no_t->endian, game->tex->no_t->width, game->tex->no_t->height);


	texX = (int)(rayon->wall_x * (double)texWidth); // /!\ texWidth est une macro (genre 64), voir comment on gere ca pour que les textures donnes soient au bon format
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
	//	buffer[y][x] = game->tex[texNum][texHeight * texY + texX];
		buffer[y][x] = *(int *)(tex_dir.addr + ((texHeight * texY) * tex_dir.line_length +  texX * (tex_dir.bits_per_pixel / 8)));
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
		if (rayon->side)
			buffer[y][x] = 255;
		else
			buffer[y][x] = 3277055;
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
