/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:29:48 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/04 16:05:00 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    s_game game;
    game.tex = ft_calloc(1, sizeof(s_texture));
    if (!game.tex)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    game.tex->fd = open(argv[1], O_RDONLY);
    game.tex->floor_t = -1;
    game.tex->ceili_t = -1;
    game.mlx = mlx_init();
    if (game.tex->fd == -1)
    {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        free(game.tex);
        return 1;
    }
    parsing(&game);
    printf("Texture structure contents:\n");
    printf("File Descriptor: %d\n", game.tex->fd);
    printf("NO Texture: %p\n", game.tex->no_t);
    printf("SO Texture: %p\n", game.tex->so_t);
    printf("WE Texture: %p\n", game.tex->we_t);
    printf("EA Texture: %p\n", game.tex->ea_t);
    printf("Floor Color: %d\n", game.tex->floor_t);
    printf("Ceiling Color: %d\n", game.tex->ceili_t);
    printf("Loaded: %d\n", game.tex->loaded);
    int i = -1;
    while (game.map[++i])
    {
        printf("%s\n", game.map[i]);
    }
    close(game.tex->fd);
    free_all(&game);
    return 0;
}


