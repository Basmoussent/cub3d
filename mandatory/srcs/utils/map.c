/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:05:39 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/11 12:35:02 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_minimap(t_game *game)
{
	game->minimap->img = mlx_new_image(game->mlx, MAP_WIDTH, MAP_HEIGHT);
	if (!game->minimap->img)
		return (0);
	game->minimap->addr = mlx_get_data_addr(game->minimap->img, &game->minimap->bits_per_pixel,
			&game->minimap->line_length, &game->minimap->endian);
	if (!game->minimap->addr)
		return (0);
  return (1);
}
//# define MAP_WIDTH 198
//# define MAP_HEIGHT 126

static int is_walkable(t_game *game, int x, int y)
{
  int real_x;
  int real_y;

  real_x = (int)game->p->pos_x + (x - 4);
  real_y = (int)game->p->pos_y + (y - 4);

  if (real_x < 0 || real_x >= (int)ft_strlen(game->map[0]) || real_y < 0 || real_y >= ft_size(game->map))   // strlen a changer
    return (0);
  if (game->map[real_y][real_x] == '0')
    return (1);
  return (0);
}

//	 7 --> cube de 18    HEIGHT
//	 9 --> cube de 22 widht 
static void fill_map(t_game *game, int **buffer)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
      if ((x / 7) < 0 || (x / 7) >= (int)ft_strlen(game->map[0]) || (y / 9) < 0 || (y / 9) >= ft_size(game->map))   // strlen a changer
        buffer[y][x] = 0; // couleur mur;
      else if ((x / 7) == 4 && (y / 9) == 4)
      {
          buffer[y][x] = 255;
          printf("y = %d, x = %d, y/9 = %d, x/7 = %d, pos y = %d, pos x = %d\n", y, x, y / 9, x / 7, (int)game->p->pos_y, (int)game->p->pos_x);
      }
      else if (is_walkable(game, x / 7, y / 9))
          buffer[y][x] = game->tex->floor_t;
			else
          buffer[y][x] = 0;// voir couleur mur;
			x++;
		}
		y++;
	}
}

static int	**init_map_buffer(t_game *game)
{
	int	**buffer;
	int	x;

	x = 0;
	buffer = ft_calloc(sizeof(int *), MAP_HEIGHT + 1);
	if (!buffer)
		return (free_all(game, 1), NULL);
	while (x < MAP_HEIGHT)
	{
		buffer[x] = ft_calloc(sizeof(int), MAP_WIDTH);
		if (!buffer[x])
			return (free_tab((void **)buffer), free_all(game, 1), NULL);
		x++;
	}
	buffer[x] = NULL;
	return (buffer);
}

int print_minimap(t_game *game)
{
  int **buffer;
  int x;
  int y;

  x = 0;
  y = 0;
  buffer = init_map_buffer(game);
  fill_map(game, buffer);

  while (y < MAP_HEIGHT)
  {
    x = 0;
    while (x < MAP_WIDTH)
    {
      my_mlx_pixel_put(game->minimap, x, y, buffer[y][x]);
			x++;
		}
		y++;
	}
  free(buffer);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap->img, WIN_WIDTH - MAP_WIDTH - 10, 10);
  return (1);
}
