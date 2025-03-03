/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:36:51 by tibarike          #+#    #+#             */
/*   Updated: 2025/03/01 17:10:01 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	fractol->r = 25;
	fractol->g = 15;
	fractol->b = 3;
	draw_fractol(fractol, fractol->name);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	hooks_handle(fractol);
	mlx_keys(fractol);
	close_mlx(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}

static int	check_sign(char *s, int *i)
{
	while (s[*i] == ' ' || s[*i] == '\t')
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
		(*i)++;
	if (s[*i] == '\0' || s[*i] == '.')
		return (1);
	return (0);
}

static int	validate_chars(char *s, int *i, int *point)
{
	while (s[*i])
	{
		if (s[*i] == '.')
		{
			if (*point == 1 || s[*i + 1] == '\0')
				return (1);
			(*point)++;
		}
		else if (s[*i] < '0' || s[*i] > '9')
			return (1);
		(*i)++;
	}
	return (0);
}

int	isvalid_num(char *s)
{
	int	i;
	int	point;

	if (!s || s[0] == '\0')
		return (1);
	i = 0;
	point = 0;
	if (check_sign(s, &i))
		return (1);
	return (validate_chars(s, &i, &point));
}
