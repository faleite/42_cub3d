/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:53:21 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/06 21:03:07 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	plot_line_high(t_image *data, t_vt_d p1, t_vt_d p2, int color)
{
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	int xi = 1;

	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int d = 2 * dx - dy;
	int x = p1.x;

	int cst1 = 2 * (dx - dy);
	int cst2 = 2 * dx;

	for (int y = p1.y; y < p2.y; y++)
	{
		img_draw_pixel(data, x, y, color);
		if (d > 0)
		{
			x += xi;
			d += cst1;
		}
		else
			d += cst2;
	}
}

// typedef struct s_bres
// {
// 	int	dx;
// 	int	dy;
// 	int	xi;
// 	int	x;
// 	int	y;
// 	int	d;
// 	int	cst1;
// 	int	cst2;
// }		t_bres;

// static void	plot_line_high(t_image *data, t_vt_d p1, t_vt_d p2, int color)
// {
// 	t_bres	bres;

// 	bres.dx = p2.x - p1.x;
// 	bres.dy = p2.y - p1.y;
// 	bres.xi = 1;
// 	if (bres.dx < 0)
// 	{
// 		bres.xi = -1;
// 		bres.dx = -bres.dx;
// 	}
// 	bres.d = 2 * bres.dx - bres.dy;
// 	bres.x = p1.x;
// 	bres.cst1 = 2 * (bres.dx - bres.dy);
// 	bres.cst2 = 2 * bres.dx;
// 	bres.y = p1.y - 1;
// 	while (++bres.y < p2.y)
// 	{
// 		img_draw_pixel(data, bres.x, bres.y, color);
// 		if (bres.d > 0)
// 		{
// 			bres.x += bres.xi;
// 			bres.d += bres.cst1;
// 		}
// 		else
// 			bres.d += bres.cst2;
// 	}
// }


static void	plot_line_low(t_image *data, t_vt_d p1, t_vt_d p2, int color)
{
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	int yi = 1;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int d = 2 * dy - dx;
	int y = p1.y;

	// Calculating const
	int cst1 = 2 * (dy - dx);
	int cst2 = 2 * dy;

	for (int x = p1.x; x < p2.x; x++)
	{
		img_draw_pixel(data, x, y, color);
		if (d > 0)
		{
			y += yi;
			d += cst1;
		}
		else
			d += cst2;
	}
}

void	ft_bresenham(t_image *img, t_vt_d p1, t_vt_d p2, int color)
{
	if (abs(p2.y - p1.y) < abs(p2.x - p1.x))
	{
		if (p1.x > p2.x)
			plot_line_low(img, p2, p1, color);
		else
			plot_line_low(img, p1, p2, color);
	}
	else
	{
		if (p1.y > p2.y)
			plot_line_high(img, p2, p1, color);
		else
			plot_line_high(img, p1, p2, color);
	}
}
