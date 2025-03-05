/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:44:59 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/05 12:10:30 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include "mlx.h"
# include "libft.h"
# include "struct.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080   // A verifier

# define WIDTH 100
# define HEIGHT 100

# define texWidth 64       // a adapter
# define texHeight 64

// PARSING
void 	parsing(s_game *g);
void 	extract_texture(s_game *g, char *line);
void 	extract_line(s_game *g, char *line);
void 	init_map(s_game *g, char *line);
int		rgb_to_hex(char *rgb);
void	free_all(s_game *g);

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
int		init_graphical(void	*mlx, void *win, t_img *img);

//key_controls.c
void	key_controls(s_game *game);

// UTILS

// free_graphical.c
void	free_graphical(int type, void *mlx, void *img, void *win);

#endif
