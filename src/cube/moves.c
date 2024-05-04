/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/04 17:40:35 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_up(t_cube *cube, int move)
{
	t_vt_f	new;

	cube->p->move = move;
	new.x = cube->p->pos.x;
	new.y = cube->p->pos.y;

	new.x += cube->p->dir.x * cube->p->move_speed * cube->p->move;
	new.y += cube->p->dir.y * cube->p->move_speed * cube->p->move;

	if (hit_wall(new.x, new.y) == 0)
	{
		cube->p->pos.x = new.x;
		cube->p->pos.y = new.y;
	}
}

// void	move_up(t_cube *cube, int move)
// {
// 	t_vt_f	new;

// 	cube->p->move = move;
// 	new.x = cube->p->pos.x;
// 	new.y = cube->p->pos.y;

// 	new.x += cube->p->dir.x * cube->p->move_speed * cube->p->move;
// 	new.y += cube->p->dir.y * cube->p->move_speed * cube->p->move;

// 	printf("NewX: %d, NewY: %d\n", (int)(new.x) / (int)TILE_SIZE, (int)(new.y) / (int)TILE_SIZE);
// 	// if (map()->map[(int)cube->p->pos.x / (int)TILE_SIZE]
// 	// 				[(int)(cube->p->pos.y + new.y) / (int)TILE_SIZE] != '1')
// 	if (map()->map[(int)new.y / (int)TILE_SIZE][(int)new.x / (int)TILE_SIZE] == '1')
// 		printf("WALL\n");
// 	if (map()->map[(int)new.y / (int)TILE_SIZE][(int)cube->p->pos.x / (int)TILE_SIZE] != '1')
// 	{
// 		// cube->p->pos.x = new.x;
// 		cube->p->pos.y = new.y;
// 	}
// 	// if (map()->map[(int)(cube->p->pos.x + new.x) / (int)TILE_SIZE]
// 	// 				[(int)cube->p->pos.y / (int)TILE_SIZE] != '1')
// 	// 	printf("WALL\n");

// 	// if (map()->map[(int)(cube->p->pos.x + new.x)]
// 	// 				[(int)cube->p->pos.y] != '1')
// 	// 	cube->p->pos.x = new.x;
// 	// if (map()->map[(int)cube->p->pos.x]
// 	// 			[(int)(cube->p->pos.y + new.y)] != '1')
// 	// 	cube->p->pos.y = new.y;

// 	// if (hit_wall(new.x, new.y) == 0)
// 	// {
// 	// 	cube->p->pos.x = new.x;
// 	// 	cube->p->pos.y = new.y;
// 	// }
// }

/**
 * printf("NewX: %d, NewY: %d\n", (int)new_pos.x / TILE_SIZE, (int)new_pos.y / TILE_SIZE);
	if (map()->map[(int)new_pos.y / TILE_SIZE][(int)new_pos.x / TILE_SIZE] == '1')
		printf("WALL");
*/
void	move_right(t_cube *cube, int move)
{
	t_vt_f	new_dir;
	t_vt_f	new_pos;

	cube->p->move = move;
	new_dir.x = cube->p->dir.x * cos(M_PI_2) * cube->p->move -\
				cube->p->dir.y * sin(M_PI_2) * cube->p->move;
	new_dir.y = cube->p->dir.x * sin(M_PI_2) * cube->p->move +\
				cube->p->dir.y * cos(M_PI_2) * cube->p->move;

	new_pos.x = cube->p->pos.x; 
	new_pos.y = cube->p->pos.y;

	new_pos.x += new_dir.x * cube->p->move_speed;
	new_pos.y += new_dir.y * cube->p->move_speed;
	if (hit_wall(new_pos.x, new_pos.y) == 0)
	{
		cube->p->pos.x = new_pos.x;
		cube->p->pos.y = new_pos.y;
	}
}

void	move_rotate(t_cube *cube, int rotate)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->p->dir.x;
	cube->p->dir.x = cube->p->dir.x * cos(rotate * cube->p->rotation_speed
					) - cube->p->dir.y * sin(rotate * cube->p->rotation_speed);
	cube->p->dir.y = old_dir_x * sin(rotate * cube->p->rotation_speed) +
						cube->p->dir.y * cos(rotate * cube->p->rotation_speed);
	old_plane_x = cube->p->plane.x;
	cube->p->plane.x = cube->p->plane.x * 
					cos(rotate * cube->p->rotation_speed) - cube->p->plane.y 
					* sin(rotate * cube->p->rotation_speed);
	cube->p->plane.y = old_plane_x * sin(rotate * cube->p->rotation_speed) + 
					cube->p->plane.y * cos(rotate * cube->p->rotation_speed);
}

// void	move_rotate(t_cube *cube, int rotate)
// {
// 	if (rotate == -1)
// 		cube->p->angle -= cube->p->rotation_speed / 100.0;
// 	if (rotate == 1)
// 		cube->p->angle += cube->p->rotation_speed / 100.0;
// }
