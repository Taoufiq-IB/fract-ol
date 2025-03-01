/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:13:41 by tibarike          #+#    #+#             */
/*   Updated: 2025/02/28 10:38:54 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	draw_fractol(t_fractol *fractol, char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		mandelbrot(fractol);
	else if (ft_strcmp(name, "julia") == 0)
		julia(fractol, fractol->x, fractol->y);
	else
		burning_ship(fractol);
}

static int	window_init(t_fractol *fractol)
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
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	fractol->r = 5;
	fractol->g = 3;
	fractol->b = 7;
	draw_fractol(fractol, fractol->name);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	hooks_handle(fractol);
	mlx_keys(fractol);
	close_mlx(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}

static void	usage_error(void)
{
	ft_putstr_fd("Usage:\n./fractol mandelbrot\n", 2);
	ft_putstr_fd("./fractol ./julia <real> <img>\n", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac <= 1)
		usage_error();
	else if (ac == 2 && ft_strcmp(av[1], "burning ship") == 0)
		fractol.name = av[1];
	else
		usage_error();
	fractol.mlx = mlx_init();
	if (window_init(&fractol) != 0)
	{
		ft_putstr_fd("something is off\n", 2);
		exit(1);
	}
	return (0);
}
