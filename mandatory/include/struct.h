/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/11 14:15:28 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/03/04 18:12:46 by agozlan          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

/*
#define WIN_WIDTH 1920
#define	WIN_HEIGHT 1080      // a verifier
*/
# define WIDTH 100
# define HEIGHT 100


typedef struct t_texture {
    char    *file;
    int     fd;
	void	*no_t;
	void	*so_t;
	void	*we_t;
	void	*ea_t;
	int		floor_t;
	int		ceili_t;
    int     loaded;
}	s_texture;

typedef struct t_player {
	int 	px; // pos_x
	int		py; // pos_y
	int		pdx; // dir_x
	int 	pdy; // dir_y
	double	plane_x; // surement 0
	double	plane_y; // surement 0.66
  
  // basem
  double  pa;
} s_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_img;

typedef struct t_game
{
	void		*mlx;
	void		*win;
	char		**map;
	s_player	*p;
	s_texture	*tex;
	t_img		*img;
}	s_game;

typedef struct t_rayon
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
	int		side;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
}	s_rayon;


enum {
	W = 119,
	S = 115,
	A = 97,
	D = 100,
	ESC = 65307,
	LEFT = 65361,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363
};

//PARSING
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

// get_rayon_data.c
void	get_rayon_data(s_game *game, s_rayon *rayon, int x);

// graphical.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int	init_graphical(void	*mlx, void *win, t_img *img);

#endif
