/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map.c											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/04 09:15:05 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/03/06 16:23:05 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

int is_enclosed(s_game *g, int y, int x)
{
	if (g->map[y][x] == '1') 
		return (1);
	if (g->map[y][x] == ' ')
		return (0);
	if (y == 0 || !g->map[y + 1] || x == 0 || g->map[y][x + 1] == '\0')
		return (0);

	if (g->map[y - 1][x] == ' ' || g->map[y + 1][x] == ' ' ||
		g->map[y][x - 1] == ' ' || g->map[y][x + 1] == ' ')
		return (0);
	return (1);
}

/* Ensure the map is enclosed by walls */
void	check_surrounded_by_walls(s_game *g)
{
	int	y;
	int	x;

	for (y = 0; g->map[y]; y++)
	{
		for (x = 0; g->map[y][x]; x++)
		{
			if (g->map[y][x] == '0' || g->map[y][x] == 'N' ||
				g->map[y][x] == 'S' || g->map[y][x] == 'E' ||
				g->map[y][x] == 'W')
			{
				if (!is_enclosed(g, y, x))
				{
					print_error("Map is not enclosed by walls\n");
					free_all(g, 1);
				}
			}
		}
	}
}

void	add_line_to_map(s_game *g, char *line, int i)
{
	char	**new_map;
	new_map = (char **)ft_realloc(g->map, sizeof(char *) * (i + 1),
		sizeof(char *) * (i + 2));
	if (!new_map)
	{
		free(line);
		return ;
	}
	g->map = new_map;
	g->map[i] = ft_strdup(line);
	g->map[i + 1] = NULL;
}


void check_case(s_game *g, char *line)
{
	int	y;
	
	y = 0;
	while (line[y])
	{
		if (!(line[y] == '0' || line[y] == '1' || line[y] == 'N'
			|| line[y] == 'S' || line[y] == 'E' || line[y] == 'W'))
		{
			printf("character - %c\n", line[y]);
			free(line);
			print_error("Unknown character encountered\n");
			free_all(g, 1);
		}
		if ((line[y] == 'N' || line[y] == 'S'
			|| line[y] == 'E' || line[y] == 'W'))
			init_player(line[y], g, line, y);
		y++;
	}
}


void extract_line(s_game *g, char *line)
{
	int i;
	int len;
		
	i = 0;
	len = ft_strlen(line);
	if (len == 1 && line[0] == '\n')
		return ;
	ft_replace(line, " \t\n\r\v\f", '1');
	check_case(g, line);
	if (g->map == NULL)
	{
		init_map(g, line);
		return;
	}
	else
	{
		while (g->map[i] != NULL)
			i++;
		add_line_to_map(g, line, i);
	}
}

void init_map(s_game * g, char *line)
{
	g->map = (char **)ft_calloc(2, sizeof(char *));
	if (!g->map)
	{
		free(line);
		return ;
	}
	g->map[0] = ft_strdup(line);
	g->map[1] = NULL;
}



