/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:32:26 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/05 11:53:02 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_button(int keycode, s_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(game->mlx, game->img->img);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		// free_game
		exit(0);
		return (0);
	}
}



int	cross_close(s_game *game)
{
	mlx_destroy_image(game->mlx, game->img->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	// free_game
	exit(0);
	return (0);
}

void	key_controls(s_game *game)
{
	mlx_hook(game->win, 17, 0, cross_close, game);
	mlx_hook(game->win, 2, 1L << 0, ft_button, game);
}
