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
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	if (!img->addr)
		return (0);
	return (1);
}

int	init_graphical(s_game *game, t_img *img)
{
	(void)img;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!game->win)
		return (free_all(game, 1), 1);
	if (!init_image(game->mlx, game->img))
		return (0);
	return (1);
}

