/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:48:29 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/05 10:26:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
  Conversao de Angulos em graus para Radianos
  Calcular seno, coseno e tangente
  Obs: Geralmente na programacao utilizamos 
  angulos em formato de radiano
*/
// int	main(void)
// {
// 	float	angulo, confere;
// 	float	seno, coseno, tangente;

// 	printf("Digite uma angulo em graus: ");
// 	scanf("%f", &angulo);
// 	/*
// 	 Conversao de graus em radianos
// 	 180˚ e igual a PI radianos
// 	 angulo˚ e igual a X radianos
// 	 formula:
// 		X = ang˚*PI/180
// 	*/
// 	angulo = (angulo * M_PI) / 180;
// 	seno = sin(angulo);
// 	coseno = cos(angulo);
// 	tangente = tan(angulo);
// 	printf("\n\tANGULO EM RADIANOS = %f", angulo);
// 	printf("\n\tSENO = %f\n\tCOSENO = %f\n\tTANGENTE = %f",\
// 			seno, coseno, tangente);
// 	// sen^2(x) + cos^2(x) = 1
// 	confere = pow(seno, 2) + pow(coseno, 2);
// 	printf("\n\tCONFERENCIA  = %f\n", confere);
// 	return (0);
// }
// // ---------------------- COllition. 

// int	ft_collition(t_cube *cube, float x, float y)
// {
// 	int		x_m;
// 	int		y_m;
//     t_map *map;

//     map = cube->map;
// 	if (x < 0 || y < 0)
// 		return (0);
// 	x_m = floor (x / TILE_SIZE);
// 	y_m = floor (y / TILE_SIZE);
// 	if ((y_m >= map->map_height || x_m >= map->map_width))
// 		return (0);
// 	if (map->map[y_m] && x_m <= (int)strlen(map->map[y_m]))
// 		if (map->map[y_m][x_m] == '1')
// 			return (0);
// 	return (1);
// }

// // -------------------- raycasting . 

// int	unit_circle(float angle, char c)
// {
// 	if (c == 'x')
// 	{
// 		if (angle > 0 && angle < M_PI)
// 			return (1);
// 	}
// 	else if (c == 'y')
// 	{
// 		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
// 			return (1);
// 	}
// 	return (0);
// }

// int	inter_check(float angle, float *inter, float *step, int is_horizon)
// {
// 	if (is_horizon)
// 	{
// 		if (angle > 0 && angle < M_PI)
// 		{
// 			*inter += TILE_SIZE;
// 			return (-1);
// 		}
// 		*step *= -1;
// 	}
//     else
// 	{
// 		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
// 		{
// 			*inter += TILE_SIZE;
// 			return (-1);
// 		}
// 		*step *= -1;
// 	}
//     return (1);
// }

// static int ft_looking_angle(float angle, t_vector_2d_f *intersect, t_vector_2d_f *delta, int flag)
// {
//     if (flag == 1)
//     {
//         if (angle > 0 && angle < M_PI ) // Looking left.
//         {
//             printf("Looking DOWN \n");
//             intersect->y += TILE_SIZE;
//             return(-1);
//         }
//         delta->y *= -1;
//     }
//     return (1);
// }


//================= math utils. 


void ft_angle_normal(float *angle)
{
    float mod_angle;

    mod_angle = 2 * M_PI;
    *angle = fmod(*angle, mod_angle);
    if (*angle < 0)
        *angle += mod_angle;
}

// t_vector_2d ft_vector_convert(t_vector_2d_f vector)
// {
//     t_vector_2d vector_double;

//     vector_double.x = (int) vector.x;
//     vector_double.y = (int) vector.y;
//     return (vector_double);
// }

// int ft_check_distance(t_vector_2d_f p1, t_vector_2d_f p2)
// {
//     double dx;
//     double dy;

//     dx = (p2.x - p1.x);
//     dy = (p2.y - p1.y);
//     return sqrt(dx * dx + dy * dy);
// }

// double ft_angle_convert(double angle)
// {
//     return (angle * (PI / 180));
// }

// void update_minimap_position(t_cube *cube)
// {
//     t_player *player;
//     t_map *map;

//     map = cube->map;
//     player = cube->player;

//     map->map_pos.x = ((player->position.x - TILE_SIZE / 2) / (TILE_SIZE) * MINIMAP_SCALE_FACTOR);
//     map->map_pos.y = ((player->position.y - TILE_SIZE / 2) / (TILE_SIZE) * MINIMAP_SCALE_FACTOR);
//     map->map_pos.angle = player->rotation_angle;
// }

// t_vector_2d update_minimap_pos(t_vector_2d_f position)
// {
//     t_vector_2d new_pos;

//     new_pos.x = ((position.x - TILE_SIZE / 2) / (TILE_SIZE) * MINIMAP_SCALE_FACTOR);
//     new_pos.y = ((position.y - TILE_SIZE / 2) / (TILE_SIZE) * MINIMAP_SCALE_FACTOR);
//     return (new_pos);
// }

// /// @brief This is based on the uniraaty circle, we will check if the angle is equal to
// /// @brief (0, PI, PI/2, 3 * PI/2) as this will give us problems in the calculus of the tan(angle)
// /// @param player
// /// @return 1 if we can calculate tan(angle) or 0 if we can not.

// int	ft_angle_check_circle(double angle, char c)
// {
// 	if (c == 'x')
// 	{
// 		if (angle > 0 && angle < M_PI)
// 			return (1);
// 	}
// 	else if (c == 'y')
// 	{
// 		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
// 			return (1);
// 	}
// 	return (0);
// }
