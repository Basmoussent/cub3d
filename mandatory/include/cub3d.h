/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:44:59 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/09 19:26:10 by bdenfir          ###   ########.fr       */
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

#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080

# define WIDTH 100
# define HEIGHT 100

#define	ROTSPEED 0.1
#define	MOVESPEED 0.125

// PARSING
void 	parsing(s_game *g);
void 	extract_texture(s_game *g, char *line);
void 	extract_line(s_game *g, char *line, int *end);
void 	init_map(s_game *g, char *line);
int		rgb_to_hex(char **rgb, s_game *g, char *line);
void	free_all(s_game *g, int status);
void	check_surrounded_by_walls(s_game *g);

// EXEC

// exec.c
int	rendering(s_game *game);
int	execution(s_game *game);

// get_color.c
void	get_color(s_game *game, s_rayon *rayon, int **buffer, int x);

// get_rayon_data.c
void	get_rayon_data(s_game *game, s_rayon *rayon, int x);

// graphical.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

//int		init_graphical(void	*mlx, void *win, t_img *img);
int	init_graphical(s_game *game);

// MOVEMENT

//key_controls.c
void	key_controls(s_game *game);

// move_player.c
void	move_player(s_game *game);

// rotate_camera.c
void	rotate_camera(s_game *game);

// free.c
void	print_error(char *msg);
int		ca_triche(s_game *g);
int		check_adjacent(s_game *g, int i, int j);

// player.c
void	init_player(char c, s_game *g, char *line, int x);
void	set_player_pos(s_game *g, int pos_x, int dir_x, int dir_y);

// free_graphical.c
void	free_graphical(int type, void *mlx, void *img, void *win);

#endif
