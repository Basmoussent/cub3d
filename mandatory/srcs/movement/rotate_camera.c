/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:31:22 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/05 13:02:08 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
To rotate a vactor, simply multiply it with the rotation matrix
[ cos(a) -sin(a) ]
[ sin(a)  cos(a) ]
(where a is the magnitude of rotation)
*/

void	rotation(s_game *game, int a)
{
	game->p->dir_x *= a;
	game->p->dir_y *= a;
	game->p->plane_x *= a;
	game->p->plane_y *= a;
}

void	rotate_camera(s_game *game, int keycode)
{
	if (keycode == 65361)
		rotation(game, 0.5); // valeur aleatoire ici
	else if (keycode == 65363)
		rotation(game, -0.5); // valeur aleatoire
	rendering(game);
}
