/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:53:21 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/07 19:29:09 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	plot_aux(t_bres	*bres, t_vt_d p1, t_vt_d p2)
{
	bres->dx = p2.x - p1.x;
	bres->dy = p2.y - p1.y;
}

static void	plot_line_high(t_image *data, t_vt_d p1, t_vt_d p2, int color)
{
	t_bres	bres;

	plot_aux(&bres, p1, p2);
	bres.xi = 1;
	if (bres.dx < 0)
	{
		bres.xi = -1;
		bres.dx = -bres.dx;
	}
	bres.d = 2 * bres.dx - bres.dy;
	bres.x = p1.x;
	bres.cst1 = 2 * (bres.dx - bres.dy);
	bres.cst2 = 2 * bres.dx;
	bres.y = p1.y - 1;
	while (++bres.y < p2.y)
	{
		img_draw_pixel(data, bres.x, bres.y, color);
		if (bres.d > 0)
		{
			bres.x += bres.xi;
			bres.d += bres.cst1;
		}
		else
			bres.d += bres.cst2;
	}
}

static void	plot_line_low(t_image *data, t_vt_d p1, t_vt_d p2, int color)
{
	t_bres	bres;

	plot_aux(&bres, p1, p2);
	bres.yi = 1;
	if (bres.dy < 0)
	{
		bres.yi = -1;
		bres.dy = -bres.dy;
	}
	bres.d = 2 * bres.dy - bres.dx;
	bres.y = p1.y;
	bres.cst1 = 2 * (bres.dy - bres.dx);
	bres.cst2 = 2 * bres.dy;
	bres.x = p1.x - 1;
	while (++bres.x < p2.x)
	{
		img_draw_pixel(data, bres.x, bres.y, color);
		if (bres.d > 0)
		{
			bres.y += bres.yi;
			bres.d += bres.cst1;
		}
		else
			bres.d += bres.cst2;
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
