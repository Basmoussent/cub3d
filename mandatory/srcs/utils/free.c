/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:38:28 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/11 17:35:42 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_game *g)
{
	char	*line;

	if (g->tex)
	{
		if (g->tex->file)
			free(g->tex->file);
		if (g->tex->no_t)
			destroy_img(g, g->tex->no_t);
		if (g->tex->so_t)
			destroy_img(g, g->tex->so_t);
		if (g->tex->we_t)
			destroy_img(g, g->tex->we_t);
		if (g->tex->ea_t)
			destroy_img(g, g->tex->ea_t);
		line = get_next_line(g->tex->fd);
		while (line)
		{
			free(line);
			line = get_next_line(g->tex->fd);
		}
		if (g->tex->fd != -1)
			close(g->tex->fd);
		free(g->tex);
	}
}

void	free_player(t_player *p)
{
	if (p)
		free(p);
}

void	free_all(t_game *g, int status)
{
	if (g)
	{
		free_tab((void **)g->map);
		free_player(g->p);
		free_texture(g);
		if (g->mlx)
		{
      if (g->minimap && g->minimap->img)
        mlx_destroy_image(g->mlx, g->minimap->img);
			if (g->img && g->img->img && g->win)
			{
				mlx_destroy_image(g->mlx, g->img->img);
				mlx_destroy_window(g->mlx, g->win);
			}
			mlx_destroy_display(g->mlx);
			free(g->mlx);
		}
		if (g->doors)
			free(g->doors);
	}
	exit(status);
}

void	print_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
}
