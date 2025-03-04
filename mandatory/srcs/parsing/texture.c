/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:13:52 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/04 09:14:06 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void parse_texture(char **tmp, s_game *g)
{
	if (tmp[0] && ft_strncmp(tmp[0], "NO", 3) == 0 && tmp[1])
		g->tex->no_t = tmp[1];
	if (tmp[0] && ft_strncmp(tmp[0], "SO", 3) == 0 && tmp[1])
		g->tex->so_t = tmp[1];
	if (tmp[0] && ft_strncmp(tmp[0], "WE", 3) == 0 && tmp[1])
		g->tex->we_t = tmp[1];
	if (tmp[0] && ft_strncmp(tmp[0], "EA", 3) == 0 && tmp[1])
		g->tex->ea_t = tmp[1];
	if (tmp[0] && ft_strncmp(tmp[0], "F", 2) == 0 && tmp[1])
		g->tex->floor_t = rgb_to_hex(tmp[1]);
	if (tmp[0] && ft_strncmp(tmp[0], "C", 2) == 0 && tmp[1])
		g->tex->ceili_t = rgb_to_hex(tmp[1]);
	if (g->tex->ceili_t && g->tex->floor_t && g->tex->no_t && g->tex->so_t && g->tex->we_t && g->tex->ea_t)
		g->tex->loaded = 1;
}

void extract_texture(s_game *g, char *line)
{
	char **tmp;
	int size;
	
	if (g->tex->loaded == 1)
		return ;
	tmp = ft_split(line, ' ');
	if (!tmp)
		return ;
	size = sizeof(tmp) / sizeof(tmp[0]);
	if (size != 2)
	{
		free_tab(tmp);
		return ;
	}
	parse_texture(tmp, g);
}
