/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:54 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/06 23:12:47 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int draw_buffer(s_game *game, int **buffer)
{
  int x;
  int y;

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

int	rendering(s_game *game)
{
	int	x;
	s_rayon	*rayon;
	int	**buffer;

	x = 0;
	rayon = ft_calloc(sizeof(s_rayon), 1);
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
/*		
		if (x == 0 || x == 500)
		{
			printf("\nPOUR X = %d\n\n", x);
			printf("camera_x = %f, dir_x, = %f, dir y = %f, delta dist x = %f, delta dist y = %f\n", rayon->camera_x, rayon->dir_x, rayon->dir_y, rayon->delta_dist_x, rayon->delta_dist_y);
			printf("step x = %d, step y = %d, side dist x = %f, side dist y = %f, map x = %d, map y = %d\n", rayon->step_x, rayon->step_y, rayon->side_dist_x, rayon->side_dist_y, rayon->map_x, rayon->map_y);
			printf("side = %d, wall_dist = %f, line height = %d, draw start = %d, draw end = %d, wall x = %f\n", rayon->side, rayon->wall_dist, rayon->line_height, rayon->draw_start, rayon->draw_end, rayon->wall_x);
			printf("\n");
		}
*/
		get_color(game, rayon, buffer, x);
		x++;
	}
	draw_buffer(game, buffer);
	free_tab((void **)buffer);
	free(rayon);
	return (1);
}

int	execution(s_game *game)
{
	rendering(game);
	key_controls(game);
//	mlx_hook(game->win, 17, 0, ca_triche, game);
	mlx_loop(game->mlx);
	return (1);
}
