/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:29:02 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/11 11:52:10 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int is_wall_or_door(char c)
{
	return (c == '1' || c == 'D');  // La porte fermée agit comme un mur
}

void	move(t_game *game, double vector_x, double vector_y)
{
	double	reste;
	double	unused;

	if (game->map[(int)game->p->pos_y][(int)vector_x] != '1')
	{
		game->p->pos_x = vector_x;
		reste = modf(vector_x, &unused);
		if (!reste && game->map[(int)game->p->pos_y][(int)vector_x - 1] == '1')
			game->p->pos_x += 0.1;
	}
	if (game->map[(int)vector_y][(int)game->p->pos_x] != '1')
	{
		game->p->pos_y = vector_y;
		reste = modf(vector_y, &unused);
		if (!reste && game->map[(int)vector_y - 1][(int)game->p->pos_y] == '1')
			game->p->pos_y += 0.1;
	}
	rendering(game);
}

void	move_player(t_game *game)
{
	if (game->key_bool[0])
	{
		if (!is_wall_or_door(game->map[(int)game->p->pos_y]
			[(int)(game->p->pos_x + game->p->dir_x * MOVESPEED)]))
			game->p->pos_x += game->p->dir_x * MOVESPEED;
		if (!is_wall_or_door(game->map[(int)(game->p->pos_y + game->p->dir_y
			* MOVESPEED)][(int)game->p->pos_x]))
			game->p->pos_y += game->p->dir_y * MOVESPEED;
	}
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
