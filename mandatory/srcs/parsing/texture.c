/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:13:52 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/06 14:44:18 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void load_texture(s_game *g, char **file, char *val, char *line)
{
    int width;
    int height;
    void *img;

	if (file[1][strlen(file[1]) - 1] == '\n')
		file[1][strlen(file[1]) - 1] = '\0';
	if (!(file[1] && ft_strlen(file[1]) >= 4
		&& !ft_strncmp(file[1] + ft_strlen(file[1]) - 4, ".xpm", 4)))
	{
		free_tab((void **)file);
		free(line);
		print_error("Texture arent in .xpm format\n");
		free_all(g, 1);
	}
	img = mlx_xpm_file_to_image(g->mlx, file[1], &width, &height);
    if (!img)
    {
        free_tab((void **)file);
		free(line);
		print_error("Failed to load texture\n");
        free_all(g, 1);
    }
    if (strcmp(val, "NO") == 0)
        g->tex->no_t = img;
    else if (strcmp(val, "SO") == 0)
        g->tex->so_t = img;
    else if (strcmp(val, "WE") == 0)
        g->tex->we_t = img;
    else if (strcmp(val, "EA") == 0)
        g->tex->ea_t = img;
}

void parse_texture(char **tmp, s_game *g, char *line)
{
	if (!g->mlx)
		return;
	if (tmp[0] && ft_strncmp(tmp[0], "NO", 3) == 0 && tmp[1])
		load_texture(g, tmp, "NO", line);
	if (tmp[0] && ft_strncmp(tmp[0], "SO", 3) == 0 && tmp[1])
		load_texture(g, tmp, "SO", line);
	if (tmp[0] && ft_strncmp(tmp[0], "WE", 3) == 0 && tmp[1])
		load_texture(g, tmp, "WE", line);
	if (tmp[0] && ft_strncmp(tmp[0], "EA", 3) == 0 && tmp[1])
		load_texture(g, tmp, "EA", line);
	if (tmp[0] && ft_strncmp(tmp[0], "F", 2) == 0 && tmp[1])
		g->tex->floor_t = rgb_to_hex(tmp, g, line);
	if (tmp[0] && ft_strncmp(tmp[0], "C", 2) == 0 && tmp[1])
		g->tex->ceili_t = rgb_to_hex(tmp, g, line);
	if (g->tex->ceili_t != -1 && g->tex->floor_t != -1 && g->tex->no_t && g->tex->so_t && g->tex->we_t && g->tex->ea_t)
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
	size = ft_size(tmp);
	if (size > 2)
	{
		free_tab((void **)tmp);
		free(line);
		print_error("Texture is not formatted correctly\n");
		free_all(g, 1);
	}
	else if (size < 2)
	{
		free_tab((void **)tmp);
		return ;	
	}
	parse_texture(tmp, g, line);
	free_tab((void **)tmp);
}
