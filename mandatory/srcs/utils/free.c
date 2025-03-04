/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:38:28 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/04 16:15:04 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <struct.h>

void	free_texture(s_texture *tex, s_game *g)
{
	if (tex)
	{
		if (tex->file)
			free(tex->file);
		if (tex->no_t)
			mlx_destroy_image(g->mlx ,tex->no_t);
		if (tex->so_t)
			mlx_destroy_image(g->mlx ,tex->so_t);
		if (tex->we_t)
			mlx_destroy_image(g->mlx ,tex->we_t);
		if (tex->ea_t)
			mlx_destroy_image(g->mlx ,tex->ea_t);
		free(tex);
	}
}
void	free_map(char **map)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
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
		free_map(g->map);
		free_player(g->p);
		free_texture(g->tex, g);
		free(g);
	}
	exit(1);
}
