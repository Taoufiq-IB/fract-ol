/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:13:41 by tibarike          #+#    #+#             */
/*   Updated: 2025/03/01 17:10:13 by tibarike         ###   ########.fr       */
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

static void	usage_error(void)
{
	ft_putstr_fd("Usage:\n./fractol mandelbrot\n", 2);
	ft_putstr_fd("./fractol ./julia <real> <img>\n", 2);
	exit(1);
}

static void	argument_parsing(int argc, char **argv, t_fractol *fractol)
{
	if (argc <= 1)
		usage_error();
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		fractol->name = argv[1];
		return ;
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0
		&& isvalid_num(argv[2]) == 0 && isvalid_num(argv[3]) == 0)
	{
		fractol->name = argv[1];
		fractol->x = ft_atod(argv[2]);
		fractol->y = ft_atod(argv[3]);
	}
	else if (argc == 2 && ft_strcmp(argv[1], "burning ship") == 0)
	{
		fractol->name = argv[1];
		return ;
	}
	else
		usage_error();
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	argument_parsing(ac, av, &fractol);
	fractol.mlx = mlx_init();
	if (window_init(&fractol) != 0)
	{
		ft_putstr_fd("something is off\n", 2);
		exit(1);
	}
	return (0);
}
