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

static void check_remaining_lines(s_game *g, char *line)
{
    char    *next_line;

    while ((next_line = get_next_line(g->tex->fd)))
    {
        if (ft_strlen(next_line) > 1 || next_line[0] != '\n')
        {
            free(line);
            free(next_line);
            print_error("Invalid content after map\n");
            free_all(g, 1);
        }
        free(next_line);
    }
}

static void process_map_line(s_game *g, char *line, int *end, int *map_started)
{
    if (ft_strlen(line) > 1 || line[0] != '\n')
    {
        *map_started = 1;
        extract_line(g, line, end);
    }
    else if (*map_started && line[0] == '\n')
    {
        check_remaining_lines(g, line);
    }
}

static void parse_textures(s_game *g, char **line)
{
    while (*line && g->tex->loaded != 1)
    {
        extract_texture(g, *line);
        free(*line);
        *line = get_next_line(g->tex->fd);
    }
}

void parsing(s_game *g)
{
    char    *line;
    int     end;
    int     map_started;
    
    map_started = 0;
    line = get_next_line(g->tex->fd);
    parse_textures(g, &line);
    while (line)
    {
        process_map_line(g, line, &end, &map_started);
        free(line);
        line = get_next_line(g->tex->fd);
    }
    check_surrounded_by_walls(g);
}
