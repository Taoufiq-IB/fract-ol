/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:13:46 by tibarike          #+#    #+#             */
/*   Updated: 2025/03/01 16:55:08 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	scale(int pixel, double max, double min, int size)
{
	return (min + (((max - min) * pixel) / size));
}

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = fractol->addr + (y * fractol->line_length + x
				* (fractol->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	coloring(int i, int max, t_fractol *fractol)
{
	int	r;
	int	g;
	int	b;

	if (i == max)
		return (0x000000);
	r = (i * fractol->r) % 256;
	g = (i * fractol->g) % 256;
	b = (i * fractol->b) % 256;
	return (r << 16 | g << 8 | b);
}

static int	mouse_wheel(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom_at_mouse(fractol, x, y, 1.05);
	else if (button == 5)
		zoom_at_mouse(fractol, x, y, 0.95);
	else
		return (0);
	draw_fractol(fractol, fractol->name);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	return (0);
}

void	hooks_handle(t_fractol *fractol)
{
	mlx_mouse_hook(fractol->win, mouse_wheel, fractol);
}
