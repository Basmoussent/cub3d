/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:50:30 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/10 15:06:39 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ca_triche(t_game *g)
{
	free_all(g, 0);
	return (0);
}

int	check_adjacent(t_game *g, int i, int j)
{
	return (i == 0 || !g->map[i + 1] || j == 0 || g->map[i][j + 1] == '\0' ||
			ft_strlen(g->map[i - 1]) <= (size_t)j || ft_strlen(g->map[i + 1])
			<= (size_t)j || g->map[i - 1][j] == ' ' || g->map[i + 1][j] == ' '
			|| g->map[i][j - 1] == ' ' || g->map[i][j + 1] == ' ');
}

void	init_keybool(t_game *g)
{
	g->key_bool[0] = 0;
	g->key_bool[1] = 0;
	g->key_bool[2] = 0;
	g->key_bool[3] = 0;
	g->key_bool[4] = 0;
	g->key_bool[5] = 0;
	g->key_bool[6] = 0;
	g->key_bool[7] = 0;
}
