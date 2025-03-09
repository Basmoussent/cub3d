/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:38:28 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/09 16:00:15 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(s_game *g)
{
	if (g->tex)
	{
		if (g->tex->file)
			free(g->tex->file);
		
		if (g->tex->no_t)
		{
			mlx_destroy_image(g->mlx, g->tex->no_t->img);
			free(g->tex->no_t);
		}
		if (g->tex->so_t)
		{
			mlx_destroy_image(g->mlx, g->tex->so_t->img);
			free(g->tex->so_t);
		}
		if (g->tex->we_t)
		{
			mlx_destroy_image(g->mlx, g->tex->we_t->img);
			free(g->tex->we_t);
		}
		if (g->tex->ea_t)
		{
			mlx_destroy_image(g->mlx, g->tex->ea_t->img);
			free(g->tex->ea_t);
		}
		if (g->tex->fd != -1)
			close(g->tex->fd);
		free(g->tex);
	}
}

void	free_player(s_player *p)
{
	if (p)
		free(p);
}

void	free_all(s_game *g, int status)
{
	char	*line;
	
	if (g)
	{
		
		line = get_next_line(g->tex->fd);
		while (line)
		{
			free(line);
			line = get_next_line(g->tex->fd);
		}
		free_tab((void **)g->map);
		free_player(g->p);
		free_texture(g);
		if (g->mlx)
		{
			mlx_destroy_image(g->mlx, g->img->img);
			mlx_destroy_window(g->mlx, g->win);
			mlx_destroy_display(g->mlx);
			free(g->mlx);
		}
	}
	exit(status);
}

void	print_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
}
