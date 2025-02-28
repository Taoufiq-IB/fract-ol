/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:09:48 by tibarike          #+#    #+#             */
/*   Updated: 2025/02/28 10:10:22 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	window_init(t_fractol *fractol)
{
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	if (!fractol->win)
		return (mlx_destroy_display(fractol->mlx), free(fractol->mlx), 1);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img)
		return (mlx_destroy_window(fractol->mlx, fractol->win),
			mlx_destroy_display(fractol->mlx), free(fractol->mlx), 1);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel,
			&fractol->line_length, &fractol->endian);
	if (!fractol->addr)
		return (destroy(fractol), 1);
	fractol->zoom = 1;
	draw_fractol(fractol, fractol->name);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	hooks_handle(fractol);
	close_mlx(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
