/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:29:48 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/06 12:04:48 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    t_img	img;

	if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    s_game game;
/*
	game.mlx = mlx_init();
    if (!game.mlx)
    {
        fprintf(stderr, "MLX initialization failed\n");
        return 1;
    }
  */
  	if (!init_graphical(&game, &img))
		return (0);
  	game.tex = ft_calloc(1, sizeof(s_texture));
    game.p = ft_calloc(1, sizeof(s_player));
    if (!game.tex)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    game.tex->fd = open(argv[1], O_RDONLY);
    game.tex->floor_t = -1;
    game.tex->ceili_t = -1;
    game.map = NULL;
    if (game.tex->fd == -1)
    {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        free(game.tex);
        return 1;
    }
    parsing(&game);
/*
    printf("Texture structure contents:\n");
    printf("File Descriptor: %d\n", game.tex->fd);
    printf("Floor Color: %d\n", game.tex->floor_t);
    printf("Ceiling Color: %d\n", game.tex->ceili_t);
    printf("Loaded: %d\n", game.tex->loaded);
*/
    int i = -1;
    while (game.map[++i])
	{
        printf("%s\n", game.map[i]);
	}

	// Init a la main player pour map de base
	game.p->pos_x = 26;
	game.p->pos_y = 11;
	game.p->dir_x = 1;
	game.p->dir_y = 0;
	game.p->plane_x = 0;
	game.p->plane_y = 0.66;

	execution(&game, &img);	
  	(void)img;
	close(game.tex->fd);
    free_all(&game);
    return 0;
}


