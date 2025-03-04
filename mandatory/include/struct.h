/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.h										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/11 14:15:28 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/12/11 17:51:19 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

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
	int px;
	int	py;
	int pdx;
	int pdy;
} s_player;

typedef struct t_game {
	char		**map;
	s_player	*p;
	s_texture	*tex;
} s_game;

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
void parsing(s_game *g);
void extract_texture(s_game *g, char *line);
void extract_line(s_game *g, char *line);

#endif