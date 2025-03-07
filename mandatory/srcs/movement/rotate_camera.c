/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:31:22 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/07 11:06:58 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
To rotate a vactor, simply multiply it with the rotation matrix
[ cos(a) -sin(a) ]
[ sin(a)  cos(a) ]
(where a is the magnitude of rotation)
*/

void	rotation(s_game *game, int index, double a)
{
	double	tmp;

	(void)index;
//  while (game->key_bool[index] == 1)
//  {
		tmp = game->p->dir_x;
		game->p->dir_x = game->p->dir_x * cos(a) - game->p->dir_y * sin(a);
		game->p->dir_y = tmp * sin(a) + game->p->dir_y * cos(a);
		tmp = game->p->plane_x;
		game->p->plane_x = game->p->plane_x * cos(a) - game->p->plane_y * sin(a);
		game->p->plane_y = tmp * sin(a) + game->p->plane_y * cos(a);
		rendering(game);
  //  usleep(200); // aleatoire
//  }
}

// Left rotate -1    / Right rotate 1

void	rotate_camera(s_game *game, int keycode)
{
	if (keycode == LEFT)  // left
		rotation(game, 4, ROTSPEED * -1); // valeur aleatoire ici
	else if (keycode == RIGHT)
		rotation(game, 5, ROTSPEED); // valeur aleatoire
}
