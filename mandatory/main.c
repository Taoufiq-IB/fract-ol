/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:55:34 by tibarike          #+#    #+#             */
/*   Updated: 2025/02/28 10:12:44 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractol(t_fractol *fractol, char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		mandelbrot(fractol);
	else
		julia(fractol, fractol->x, fractol->y);
}

static void	usage_error(void)
{
	ft_putstr_fd("Usage:\n./fractol mandelbrot\n", 2);
	ft_putstr_fd("./fractol ./julia <real> <img>\n", 2);
	exit(1);
}

static int	isvalid_num(char *s)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (!s || s[0] == '\0')
		return (1);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0' || s[i] == '.')
		return (1);
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (point == 1 || s[i + 1] == '\0')
				return (1);
			point++;
		}
		else if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
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
		if (ft_atod(argv[2]) <= 2 || ft_atod(argv[2]) >= -2
			|| ft_atod(argv[3]) <= 2 || ft_atod(argv[3]) >= -2)
		{
			fractol->x = ft_atod(argv[2]);
			fractol->y = ft_atod(argv[3]);
		}
		else
			(ft_putstr_fd("invalid coords\n", 2), exit(1));
	}
	else
		usage_error();
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	argument_parsing(argc, argv, &fractol);
	fractol.mlx = mlx_init();
	if (window_init(&fractol) != 0)
	{
		ft_putstr_fd("something is off\n", 2);
		exit(1);
	}
	return (0);
}
