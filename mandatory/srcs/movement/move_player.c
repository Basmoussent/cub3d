/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:29:02 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/10 15:05:21 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_game *game, double vector_x, double vector_y)
{
	if (game->map[(int)game->p->pos_y][(int)vector_x] != '1')
		game->p->pos_x = vector_x;
	if (game->map[(int)vector_y][(int)game->p->pos_x] != '1')
		game->p->pos_y = vector_y;
	rendering(game);
}

void	move_player(t_game *game)
{
	if (game->key_bool[0])
		move(game, game->p->pos_x + game->p->dir_x * MOVESPEED,
			game->p->pos_y + game->p->dir_y * MOVESPEED);
	if (game->key_bool[1])
		move(game, game->p->pos_x - game->p->dir_x * MOVESPEED,
			game->p->pos_y - game->p->dir_y * MOVESPEED);
	if (game->key_bool[2])
		move(game, game->p->pos_x + game->p->dir_y * MOVESPEED,
			game->p->pos_y - game->p->dir_x * MOVESPEED);
	if (game->key_bool[3])
		move(game, game->p->pos_x - game->p->dir_y * MOVESPEED,
			game->p->pos_y + game->p->dir_x * MOVESPEED);
}
