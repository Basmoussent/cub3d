/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:53:45 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/06 12:01:54 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	init_image(void *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	if (!img->addr)
		return (1);
	return (0);
}

int	init_graphical(s_game *g)
{
	g->mlx = mlx_init();
	g->img = ft_calloc(1, sizeof(t_img));
	if (!g->mlx)
		return (1);
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!g->win)
		return (free_graphical(1, g->mlx, NULL, NULL), 0);
	if (!init_image(g->mlx, g->img))
		free_all(g, 1);
	return (0);
}

