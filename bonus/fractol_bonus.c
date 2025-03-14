/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:13:08 by tibarike          #+#    #+#             */
/*   Updated: 2025/03/01 16:19:13 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	iterating_man(double real, double imag)
{
	int		i;
	double	new_real;
	double	new_imag;
	double	tmp;

	new_real = real;
	new_imag = imag;
	i = 0;
	while (((new_real * new_real) + (new_imag * new_imag) < 4) && i < 100)
	{
		tmp = (new_real * new_real) - (new_imag * new_imag) + real;
		new_imag = 2 * new_real * new_imag + imag;
		new_real = tmp;
		i++;
	}
	return (i);
}

static int	iterating_julia(double real, double imag, double r, double im)
{
	int		i;
	double	new_real;
	double	new_imag;
	double	tmp;

	new_real = real;
	new_imag = imag;
	i = 0;
	while (((new_real * new_real) + (new_imag * new_imag) < 4) && i < 100)
	{
		tmp = (new_real * new_real) - (new_imag * new_imag) + r;
		new_imag = 2 * new_real * new_imag + im;
		new_real = tmp;
		i++;
	}
	return (i);
}

void	mandelbrot(t_fractol *frac)
{
	int		x;
	int		y;
	int		color;
	double	real;
	double	imag;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = scale(x, 2.0, -2.0, WIDTH) * frac->zoom + frac->offset_x;
			imag = scale(y, 2.0, -2.0, HEIGHT) * frac->zoom + frac->offset_y;
			color = coloring(iterating_man(real, imag), 100, frac);
			put_pixel(frac, x, y, color);
			x++;
		}
		y++;
	}
}

void	julia(t_fractol *frac, double j_x, double j_y)
{
	int		x;
	int		y;
	int		color;
	double	real;
	double	imag;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = scale(x, 2.0, -2.0, WIDTH) * frac->zoom + frac->offset_x;
			imag = scale(y, 2.0, -2.0, HEIGHT) * frac->zoom + frac->offset_y;
			color = coloring(iterating_julia(real, imag, j_x, j_y), 100, frac);
			put_pixel(frac, x, y, color);
			x++;
		}
		y++;
	}
}
