/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:13:08 by tibarike          #+#    #+#             */
/*   Updated: 2025/02/28 10:16:17 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterating_man(double real, double imag)
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

int	iterating_julia(double real, double imag, double r, double im)
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

void	mandelbrot(t_fractol *fractol)
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
			real = scale(x, 1.0, -2.0, WIDTH) * fractol->zoom;
			imag = scale(y, 1.5, -1.5, HEIGHT) * fractol->zoom;
			color = coloring(iterating_man(real, imag), 100);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
}

void	julia(t_fractol *fractol, double j_x, double j_y)
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
			real = scale(x, -2.0, 2.0, WIDTH) * fractol->zoom;
			imag = scale(y, 2.0, -2.0, HEIGHT) * fractol->zoom;
			color = coloring(iterating_julia(real, imag, j_x, j_y), 100);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
}
