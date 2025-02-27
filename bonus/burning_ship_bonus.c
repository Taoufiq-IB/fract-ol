/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:37:07 by tibarike          #+#    #+#             */
/*   Updated: 2025/02/27 21:04:20 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	iterating_bs(double real, double image)
{
	int		i;
	double	new_real;
	double	new_image;
	double	tmp;
	
	new_real = real;
	new_image = image;
	i = 0;
	while (((new_real * new_real) + (new_image * new_image) < 4) && i < 100)
	{
		tmp = (new_real * new_real) - (new_image * new_image) + real;
		new_image = fabs(2 * new_real * new_image) + image;
		new_real = fabs(tmp);
		i++;
	}
	return (i);
}

void	burning_ship(t_fractol *fractol)
{
	int		x;
	int		y;
	int		color;
	double	real;
	double	image;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = scale(x, 2.0, -2.0, WIDTH) * fractol->zoom + fractol->offset_x;
			image = scale(y, 2.0, -2.0, HEIGHT) * fractol->zoom + fractol->offset_y;
			color = coloring (iterating_bs(real, image), 100, fractol);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
}
