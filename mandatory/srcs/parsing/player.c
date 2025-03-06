/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:09:17 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/06 11:45:25 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_player(char c, s_game *g, char *line, int x)
{
	if (g->p->dir_x != -2)
	{
		free(line);
		print_error("This isn't a multiplayer game unfortunately\n");
		free_all(g, 1);
	}
	if (c == 'N')
		set_player_pos(g, x, 0, 1);
	if (c == 'S')
		set_player_pos(g, x, 0, -1);
	if (c == 'E')
		set_player_pos(g, x, 1, 0);
	if (c == 'W')
		set_player_pos(g, x, -1, 0);
		
}

void set_player_pos(s_game *g, int pos_x, int dir_x, int dir_y)
{
	int i;

	i = -1;
	while(g->map[++i])
		;
	g->p->dir_x = dir_x;
	g->p->dir_x = dir_y;
	g->p->pos_x = pos_x;
	g->p->pos_y = i;
}
