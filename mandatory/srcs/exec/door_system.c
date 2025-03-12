/* ************************************************************************** */
/*                                      */
/*                            :::     ::::::::   */
/*   door_system.c                    :+:   :+:    :+:   */
/*                          +:+ +:+       +:+    */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+    */
/*                        +#+#+#+#+#+   +#+     */
/*   Created: 2025/03/11 10:00:00 by bdenfir           #+#  #+#          */
/*   Updated: 2025/03/11 16:36:28 by bdenfir          ###   ########.fr    */
/*                                      */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/time.h>

void init_door_struct(t_game *game, int x, int y, int *door_count)
{
    game->doors[*door_count].x = x;
    game->doors[*door_count].y = y;
    game->doors[*door_count].is_open = 0;
    gettimeofday(&game->doors[*door_count].time, NULL);
    (*door_count)++;
}

void find_doors(t_game *game, int door_count)
{
    int x;
    int y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'D')
                init_door_struct(game, x, y, &door_count);
            x++;
        }
        y++;
    }
}

void    init_doors(t_game *game)
{
    int y;
    int door_count;

    door_count = 0;
    y = -1;
    while (game->map[++y])
        door_count += occur(game->map[y], 'D');
    game->nb_doors = door_count;
    game->doors = ft_calloc(door_count, sizeof(t_door));
    if (!game->doors)
        free_all(game, 1);
    find_doors(game, 0);
}

int  is_player_on_door(t_game *game, int door_x, int door_y)
{
    double  buffer;
        
    buffer = 0.5;
    if ((int)game->p->pos_x == door_x && (int)game->p->pos_y == door_y)
        return (1);
    if (fabs(game->p->pos_x - door_x) < buffer && 
        fabs(game->p->pos_y - door_y) < buffer)
        return (1);
        
    return (0);
}

void update_door_state(t_game *game, t_door *door, struct timeval current_time)
{
    door->is_open = !door->is_open;
    door->time = current_time;
    if (door->is_open)
        game->map[door->y][door->x] = 'O';
    else
        game->map[door->y][door->x] = 'D';
    rendering(game);
}

void    update_doors(t_game *game)
{
    struct timeval  current_time;
    int             i;
    long            elapsed;

    gettimeofday(&current_time, NULL);
    i = -1;
    while (++i < game->nb_doors)
    {
        elapsed = (current_time.tv_sec - game->doors[i].time.tv_sec) 
                * 1000000 + (current_time.tv_usec - game->doors[i].time.tv_usec);
        if (elapsed >= 10000000)
        {
            if (game->doors[i].is_open && 
                is_player_on_door(game, game->doors[i].x, game->doors[i].y))
                game->doors[i].time = current_time;
            else
                update_door_state(game, &game->doors[i], current_time);
        }
    }
}