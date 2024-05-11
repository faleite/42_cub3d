/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:29:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/11 09:03:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	keyboard(int keycode, t_cube *cube);
void	keyboard_release(int key, t_cube *cube);

int	build_window(t_cube cube)
{
	cube.mlx_ptr = mlx_init();
	if (!cube.mlx_ptr)
		return (1);
	cube.win_ptr = mlx_new_window(cube.mlx_ptr, W_WIDTH, W_HEIGHT, "cub3D");
	if (!cube.win_ptr)
	{
		free(cube.win_ptr);
		return (1);
	}
	texture_xpm_to_image(&cube);
	cube.img.mlx_img = mlx_new_image(cube.mlx_ptr, W_WIDTH, W_HEIGHT);
	cube.img.addr = mlx_get_data_addr(cube.img.mlx_img, &cube.img.bpp, \
					&cube.img.line_len, &cube.img.endian);
	mlx_hook(cube.win_ptr, 2, 1L, (void *)keyboard, &cube);
	mlx_hook(cube.win_ptr, 3, (1L << 1), (void *)keyboard_release, &cube);
	mlx_hook(cube.win_ptr, 17, 0L, (void *)destroy_window, &cube);
	mlx_hook(cube.win_ptr, 6, (1L << 6), ft_mouse_handlertrack, &cube);
	mlx_loop_hook(cube.mlx_ptr, &render_cub3d, &cube);
	mlx_loop(cube.mlx_ptr);
	return (0);
}

int	render_cub3d(t_cube *cube)
{
	if (!cube->mlx_ptr)
		return (1);
	clear_img(cube->img);
	draw_ceil_floor(&cube->img);
	raycasting(cube);
	render_minimap(cube);
	draw_player(cube, (cube->p->pos.x / TILE_SIZE), \
				(cube->p->pos.y / TILE_SIZE));
	render_rays(cube);
	ft_player_movement(cube);
	drawCircleWithCross(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, \
							cube->img.mlx_img, 0, 0);
	return (0);
}
