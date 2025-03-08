/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:29:02 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/07 16:13:55 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(s_game *game, int index, double vector_x, double vector_y)
{
	// 1.2 = player->speed, voir comment implementer
	(void)index;
	//	while(game->key_bool[index] == 1)
//  {
    if (game->map[(int)game->p->pos_x][(int)vector_x] != 1)
	  	game->p->pos_x = vector_x;
  	if (game->map[(int)vector_y][(int)game->p->pos_x] != 1)
		  game->p->pos_y = vector_y;
	  rendering(game);
//    usleep(200); // aleatoire
//  }
}

void	move_player(s_game *game)
{
	if (game->key_bool[0])
		move(game, 0, game->p->pos_x + game->p->dir_x * MOVESPEED, game->p->pos_y + game->p->dir_y * MOVESPEED);
	if (game->key_bool[1])
		move(game, 1, game->p->pos_x - game->p->dir_x * MOVESPEED, game->p->pos_y - game->p->dir_y * MOVESPEED);
	if (game->key_bool[2])
		move(game, 2, game->p->pos_x + game->p->dir_y * MOVESPEED, game->p->pos_y - game->p->dir_x * MOVESPEED);
	if (game->key_bool[3])
		move(game, 3, game->p->pos_x - game->p->dir_y * MOVESPEED, game->p->pos_y + game->p->dir_x * MOVESPEED);
}
