/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:50:30 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/10 13:03:08 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ca_triche(s_game *g)
{
	free_all(g, 0);
	return (0);
}

int	check_adjacent(s_game *g, int i, int j)
{
	return (i == 0 || !g->map[i + 1] || j == 0 || g->map[i][j + 1] == '\0' ||
			ft_strlen(g->map[i - 1]) <= (size_t)j || ft_strlen(g->map[i + 1])
			<= (size_t)j || g->map[i - 1][j] == ' ' || g->map[i + 1][j] == ' '
			|| g->map[i][j - 1] == ' ' || g->map[i][j + 1] == ' ');
}
