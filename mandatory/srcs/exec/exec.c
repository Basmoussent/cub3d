/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:54 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/04 15:34:22 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h" // a changer

int	rendering(s_game *game)
{
	


}

int	execution(s_game *game)
{
	if (!init_graphical(game->mlx, game->win, game->img))
		return (0);

	// fonction de base

	// mlx_put_image_to_window(game->mlx, game->win, game->img->img, 1, 1);
	key_controls()  // a faire
	mlx_loop(game->mlx);
	return (1);
}
