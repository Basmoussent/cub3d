/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:31:22 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/09 15:21:23 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
To rotate a vactor, simply multiply it with the rotation matrix
[ cos(a) -sin(a) ]
[ sin(a)  cos(a) ]
(where a is the magnitude of rotation)
*/

void	rotation(s_game *game, double a)
{
	double	tmp;

	tmp = game->p->dir_x;
	game->p->dir_x = game->p->dir_x * cos(a) - game->p->dir_y * sin(a);
	game->p->dir_y = tmp * sin(a) + game->p->dir_y * cos(a);
	tmp = game->p->plane_x;
	game->p->plane_x = game->p->plane_x * cos(a) - game->p->plane_y * sin(a);
	game->p->plane_y = tmp * sin(a) + game->p->plane_y * cos(a);
	rendering(game);
}

// Left rotate -1    / Right rotate 1

void	rotate_camera(s_game *game)
{
	if (game->key_bool[4])  // left
		rotation(game, ROTSPEED * -1); // valeur aleatoire ici
	if (game->key_bool[5])
		rotation(game, ROTSPEED); // valeur aleatoire
}
