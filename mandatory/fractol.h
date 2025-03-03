/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:21:29 by tibarike          #+#    #+#             */
/*   Updated: 2025/03/01 17:06:18 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_fractol
{
	char	*name;
	void	*mlx;
	void	*win;
	void	*img;
	double	zoom;
	double	x;
	double	y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
}				t_fractol;

int		window_init(t_fractol *fractol);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(const char *str1, const char *str2);
int		isvalid_num(char *s);
double	ft_atod(char *s);
void	mandelbrot(t_fractol *fractol);
void	julia(t_fractol *fractol, double j_x, double j_y);
double	scale(int pixel, double max, double min, int size);
void	put_pixel(t_fractol *fractol, int x, int y, int color);
int		coloring(int i, int max);
void	draw_fractol(t_fractol *fractol, char *name);
void	hooks_handle(t_fractol *fractol);
void	destroy(t_fractol *fractol);
void	close_mlx(t_fractol *fractol);

#endif
