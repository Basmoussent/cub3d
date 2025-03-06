/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/04 08:06:41 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/03/05 10:52:10 by agozlan          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_hex(char **rgb, s_game *game, char *line)
{
	char	**rgb_values;
	int		r;
	int		g;
	int		b;
	
	rgb_values = ft_split(rgb[1], ',');
	if (!rgb_values)
	{
		free((void **)rgb);
		free(line);
		free_all(game, 1);
	}
	if (ft_size(rgb_values) != 3)
	{
		free((void **)rgb);
		free(line);
		free_all(game, 1);
	}
	r = ft_atoi(rgb_values[0]);
	g = ft_atoi(rgb_values[1]);
	b = ft_atoi(rgb_values[2]);
	free_tab((void **)rgb_values);
	return (r << 16 | g << 8 | b);
}

void parsing(s_game *g)
{
	char	*line;
	
	line = get_next_line(g->tex->fd);
	while (line && g->tex->loaded != 1)
	{
		extract_texture(g, line);
		free(line);
		line = get_next_line(g->tex->fd);
	}
	while (line)
	{
		extract_line(g, line);
		free(line);
		line = get_next_line(g->tex->fd);
	}
	check_surrounded_by_walls(g);
	free(line);
}
