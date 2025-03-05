/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:38:28 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/05 17:36:57 by bdenfir          ###   ########.fr       */
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
			mlx_destroy_image(g->mlx, g->tex->no_t);
		if (g->tex->so_t)
			mlx_destroy_image(g->mlx, g->tex->so_t);
		if (g->tex->we_t)
			mlx_destroy_image(g->mlx, g->tex->we_t);
		if (g->tex->ea_t)
			mlx_destroy_image(g->mlx, g->tex->ea_t);
		free(g->tex);
	}
}

void free_map(s_game *g)
{
    int i;
    
    if (!g || !g->map)
        return;
        
    i = 0;
    while (g->map[i])
    {
        free(g->map[i]);
        g->map[i] = NULL;
        i++;
    }
    free(g->map);
    g->map = NULL;
}
void	free_player(s_player *p)
{
	if (p)
		free(p);
}

void	free_all(s_game *g)
{
	if (g)
	{
		char *line;
		
		line = get_next_line(g->tex->fd);
		while (line)
		{
			free(line);
			line = get_next_line(g->tex->fd);
		}
		free_map(g);
		free_player(g->p);
		free_texture(g);
		if (g->mlx)
		{
			mlx_destroy_display(g->mlx);
			free(g->mlx);
		}
	}
	exit(1);
}
