/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:44:59 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/12 13:22:15 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "../../libft/libft.h"
# include "struct.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define MAP_WIDTH 198
# define MAP_HEIGHT 198

# define ROTSPEED 0.1
# define MOVESPEED 0.125

// PARSING
void	parsing(t_game *g);
void	extract_texture(t_game *g, char *line);
void	extract_line(t_game *g, char *line, int *end);
void	init_map(t_game *g, char *line);
int		rgb_to_hex(char **rgb, t_game *g, char *line);
void	free_all(t_game *g, int status);
void	check_surrounded_by_walls(t_game *g);

// EXEC

// exec.c
int		rendering(t_game *game);
int		execution(t_game *game);

// get_color.c
void	get_color(t_game *game, t_rayon *rayon, int **buffer, int x);

// get_rayon_data.c
void	get_rayon_data(t_game *game, t_rayon *rayon, int x);

// graphical.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

//int		init_graphical(void	*mlx, void *win, t_img *img);
int		init_graphical(t_game *game);

// MOVEMENT

//key_controls.c
void	key_controls(t_game *game);

// move_player.c
void	move_player(t_game *game);

// rotate_camera.c
void	rotate_camera(t_game *game);

// door_system.c
void    update_doors(t_game *game);
void    init_doors(t_game *game);

// free.c
void	print_error(char *msg);
int		ca_triche(t_game *g);
int		check_adjacent(t_game *g, int i, int j);
void	destroy_img(t_game *g, t_img *img);
void	handle_malloc_fail(t_game *g, char **file, char *line, t_img *img);
void	check_file_format(char **file, char *line, t_img *img, t_game *g);
void	init_keybool(t_game *g);

// player.c
void	init_player(char c, t_game *g, char *line, int x);
void	set_player_pos(t_game *g, int pos_x, int dir_x, int dir_y);

// free_graphical.c
void	free_graphical(int type, void *mlx, void *img, void *win);

// map.c
int init_minimap(t_game *game);
int print_minimap(t_game *game);

// Door system
void    init_doors(t_game *game);
void    update_doors(t_game *game);

#endif
