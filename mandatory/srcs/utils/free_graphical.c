/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:25:31 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/04 18:25:48 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	free_graphical(int type, void *mlx, void *img, void *win)
{
	if (type == 3)
		mlx_destroy_image(mlx, img);
	if (type >= 2)
		mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
}
