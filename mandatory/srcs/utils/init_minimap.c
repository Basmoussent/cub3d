/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:15:53 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/12 13:16:03 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_minimap(t_game *game)
{
	game->minimap->img = mlx_new_image(game->mlx, MAP_WIDTH, MAP_HEIGHT);
	if (!game->minimap->img)
		return (0);
	game->minimap->addr = mlx_get_data_addr(game->minimap->img,
			&game->minimap->bits_per_pixel, &game->minimap->line_length,
			&game->minimap->endian);
	if (!game->minimap->addr)
		return (0);
	return (1);
}
