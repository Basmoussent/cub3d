/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rayon_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:43:10 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/04 17:13:52 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	get_step(s_game *game, s_rayon *rayon)
{
	if (rayon->dir_x < 0)
	{
		rayon->step_x = -1;
		rayon->side_dist_x = (game->p->pos_x - rayon->map_x) * rayon->delta_dist_x;
	}
	else
	{
		rayon->step_x = 1;
		rayon->side_dist_x = (rayon->map_x + 1.0 - game->p->pos_x) * rayon->delta_dist_x;
	}
	if (rayon->dir_y < 0)
	{
		rayon->step_y = -1;
		rayon->side_dist_y = (game->p->pos_y - rayon->map_y) * rayon->delta_dist_y;
	}
	else
	{
		rayon->step_y = 1;
		rayon->side_dist_y = (rayon->map_y + 1.0 - game->p->pos_y) * rayon->delta_dist_y;
	}
}

void	dda(s_game *game, s_rayon *rayon)
{
	while (1)
	{
		if (rayon->side_dist_x < rayon->side_dist_y)
		{
			rayon->side_dist_x += rayon->delta_dist_x;
			rayon->map_x += rayon->step_x;
			rayon->side = 0;
		}
		else
		{
			rayon->side_dist_y += rayon->delta_dist_y;
			rayon->map_y += rayon->step_y;
			rayon->side = 1;
		}
		if (game->map[rayon->map_x][rayon->map_y] == 1)
			break ;
	}
}

void	wall_height(s_game *game, s_rayon *rayon)
{
	if (rayon->side == 0)
		rayon->wall_dist = (rayon->map_x - game->p->pos_x + (1 - rayon->step_x) / 2) / rayon->dir_x;
	else
		rayon->wall_dist = (rayon->map_y - game->p->pos_y + (1 - rayon->step_y) / 2) / rayon->dir_y;
	rayon->line_height = (int)(WIN_HEIGHT / wall_dist);
	rayon->draw_start = -rayon->line_height / 2 + WIN_HEIGHT / 2;
	if (rayon->draw_start < 0)
		rayon->draw_start = 0;
	rayon->draw_end = rayon->line_height / 2 + WIN_HEIGHT / 2;
	if (rayon->draw_end >= WIN_HEIGHT)
		rayon->draw_end = WIN_HEIGHT - 1;
	if (rayon->side == 0)
		rayon->wall_x = rayon->pos_y + rayon->wall_dist * rayon->dir_y;
	else
		rayon->wall_x = rayon->pos_x + rayon->wall_dist * rayon->dir_x;
	rayon->wall_x = floor(rayon->wall_x);
}

void	get_rayon_data(s_game *game, s_rayon *rayon, int x)
{
	// Calculating the ray direction
	rayon->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	rayon->dir_x = game->p->dir_x + game->p->plane_x * rayon->camera_x;	
	rayon->dir_y = game->p->dir_y + game->p->plane_y * rayon->camera_x;	

	// Calculating the delta distance
	rayon->map_x = (int)game->p->pos_x;
	rayon->map_y = (int)game->p->pos_y;
	rayon->delta_dist_x = fabs(1/ rayon->dir_x);
	rayon->delta_dist_y = fabs(1/ rayon->dir_y);

	// Calculating the step and initial side distance
	get_step(game, rayon);

	// Performing DDA
	dda(game, rayon);

	// Wall height
	wall_height(game, rayon);	
}
