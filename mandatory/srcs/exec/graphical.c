/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:53:45 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/05 11:05:20 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	init_image(void *mlx, void *win, t_img *img)
{
	img->img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img)
		return (free_graphical(2, mlx, NULL, win), 0);  // free graphical a coder
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_lenght, &img->endian);
	if (!img->addr)
		return (free_graphical(3, mlx, img->img, win), 0);  // free graphical a coder
	return (1);
}

int	init_graphical(void	*mlx, void *win, t_img *img)
{
	mlx = mlx_init();
	if (!mlx)
		return (0);
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!win)
		return (free_graphical(1, mlx, NULL, NULL), 0);  // free graphical a coder
	if (!init_image(mlx, win, img))
		return (0);
	return (1);
}

