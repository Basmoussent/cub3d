/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:29:02 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/05 13:24:21 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(s_game *game, int vector_x, int vector_y)
{
	// 1.2 = player->speed, voir comment implementer
	if (game->map[(int)(game->p->pos_y)][(int)(game->p->pos_x + vector_x)] != 1)
		game->p->pos_x += vector_x;
	if (game->map[(int)(game->p->pos_y + vector_y)][(int)game->p->pos_x] != 1)
		game->p->pos_y += vector_y;
}

void	move_player(s_game *game, int keycode)
{
	if (keycode == 119)
		move(game, game->p->dir_x * 1.2, game->p->dir_y * 1.2);
	else if (keycode == 115)
		move(game, -game->p->dir_x * 1.2, -game->p->dir_y * 1.2);
	else if (keycode == 97)
		move(game, -game->p->plane_x * 1.2, -game->p->plane_y * 1.2);
	else if (keycode == 100)
		move(game, game->p->plane_x * 1.2, game->p->plane_y * 1.2);
	rendering(game);
}
