/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:20:40 by tibarike          #+#    #+#             */
/*   Updated: 2025/02/28 10:21:04 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
}

int	esc(int keycode, t_fractol *fractol)
{
	if (keycode == 65307)
	{
		destroy(fractol);
		exit(0);
	}
	return (0);
}

int	close_b(t_fractol *fractol)
{
	destroy(fractol);
	exit(0);
	return (0);
}

void	close_mlx(t_fractol *fractol)
{
	mlx_hook(fractol->win, 2, 1, esc, fractol);
	mlx_hook(fractol->win, 17, 0, close_b, fractol);
}
