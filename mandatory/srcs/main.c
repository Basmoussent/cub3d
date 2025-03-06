/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   main.c			:+:   :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2025/03/04 07:29:48 by bdenfir		   #+#  #+#		  */
/*   Updated: 2025/03/06 12:38:23 by bdenfir		  ###   ########.fr	*/
/*									  */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(s_game *g, char *file)
{
	g->tex = ft_calloc(1, sizeof(s_texture));
	g->p = ft_calloc(1, sizeof(s_player));
	g->mlx = NULL;
	g->map = NULL;
	if (!g->tex || !g->p)
		free_all(g, 1);
	g->tex->fd = open(file, O_RDONLY);
	if (g->tex->fd == -1)
	{
		print_error("Failed to open file\n");
		free_all(g, 127);
	}
	if (!init_graphical(g))
		free_all(g, 1);
  	
	g->tex->floor_t = -1;
	g->tex->ceili_t = -1;
	g->p->dir_x = -2;
}

int main(int argc, char **argv)
{
	s_game  game;
	t_img	img;
		
	if (argc != 2)
		print_error("Usage: ./cub3d <map.cub>");
	if (argv[1] && ft_strlen(argv[1]) >= 4
		&& !ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
   	{
		game.img = &img;
		init_game(&game, argv[1]);
		parsing(&game);
		execution(&game);	
		free_all(&game, 0);
	}
	else
	{
		print_error("Wrong file extension. only .cub are supported\n");
		return (1);  
	}
	return 0;
}


