/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:39:47 by tibarike          #+#    #+#             */
/*   Updated: 2025/02/28 10:44:14 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	color_shifting(t_fractol *frac, int i)
{
	frac->r += i;
	frac->g += i;
	frac->b += i;
}

void	zoom_at_mouse(t_fractol *frac, int x, int y, double zoom_factor)
{
	double	mouse_real;
	double	mouse_imag;

	mouse_real = scale(x, 2.0, -2.0, WIDTH) * frac->zoom + frac->offset_x;
	mouse_imag = scale(y, 2.0, -2.0, HEIGHT) * frac->zoom + frac->offset_y;
	frac->zoom *= zoom_factor;
	frac->offset_x = mouse_real - (scale(x, 2.0, -2.0, WIDTH)) * frac->zoom;
	frac->offset_y = mouse_imag - (scale(y, 2.0, -2.0, HEIGHT)) * frac->zoom;
}

int	handle_key(int keycode, t_fractol *frac)
{
	if (keycode == 65362)
		frac->offset_y -= 0.5 * frac->zoom;
	else if (keycode == 65364)
		frac->offset_y += 0.5 * frac->zoom;
	else if (keycode == 65361)
		frac->offset_x -= 0.5 * frac->zoom;
	else if (keycode == 65363)
		frac->offset_x += 0.5 * frac->zoom;
	else if (keycode == 61)
		color_shifting(frac, 1);
	else if (keycode == 45)
		color_shifting(frac, -1);
	burning_ship(frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
	return (0);
}

void	mlx_keys(t_fractol *frac)
{
	mlx_key_hook(frac->win, handle_key, frac);
}
