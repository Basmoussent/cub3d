/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   struct.h										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/11 14:15:28 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/03/05 10:54:23 by agozlan		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	 s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct t_texture {
	char	*file;
	int	 fd;
	t_img	*no_t;
	t_img	*so_t;
	t_img	*we_t;
	t_img	*ea_t;
	int		floor_t;
	int		ceili_t;
	int	 loaded;
}	s_texture;

typedef struct t_player {
	int 	pos_x; // px
	int		pos_y; // py
	int		dir_x; // pdx
	int 	dir_y; // pdy
	double	plane_x; // surement 0
	double	plane_y; // surement 0.66
  
  // basem -> si t'en as pas besoin enleve la
  double  pa;
} s_player;


typedef struct t_game
{
	void		*mlx;
	void		*win;
	char		**map;
	s_player	*p;
	s_texture	*tex;
	t_img		*img;
  int     *key_bool;
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

#endif
