/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:29:48 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/06 11:57:41 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_game(s_game *g, char *file)
{
  	if (!init_graphical(&game, &img))
		  return (0);
  	game.tex = ft_calloc(1, sizeof(s_texture));
    game.p = ft_calloc(1, sizeof(s_player));
    if (!game.tex)
      g->tex->fd = open(file, O_RDONLY);
      g->tex->floor_t = -1;
      g->tex->ceili_t = -1;
      g->p->dir_x = -2;
      g->map = NULL;
      g->img = NULL;
    if (g->tex->fd == -1)
    {
        print_error("Failed to open file");
        free_all(g, 127);
    }
}

int main(int argc, char **argv)
{
    s_game  game;
    
    if (argc != 2)
        print_error("Usage: ./cub3d <map.cub>");
    init_game(&game, argv[1]);
    parsing(&game);
    execution(&game, &img);	
  	(void)img;
	  close(game.tex->fd);
    free_all(&game);
    printf("texture Loaded: %d\n", game.tex->loaded);
    printf("Player:\nx,y = %d,%d\n(x,y) = %d,%d", game.p->pos_x, game.p->pos_y, game.p->dir_x, game.p->dir_y);
    free_all(&game, 0);
    return 0;
}


