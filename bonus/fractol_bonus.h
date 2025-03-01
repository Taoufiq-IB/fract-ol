/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:48:50 by tibarike          #+#    #+#             */
/*   Updated: 2025/02/28 10:51:04 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_fractol
{
	char	*name;
	void	*mlx;
	void	*win;
	void	*img;
	double	zoom;
	double	x;
	double	y;
	int		r;
	int		g;
	int		b;
	double	offset_x;
	double	offset_y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color_shift;
	char	*addr;
}				t_fractol;

void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(const char *str1, const char *str2);
void	draw_fractol(t_fractol *fractol, char *name);
void	mandelbrot(t_fractol *fractol);
void	julia(t_fractol *fractol, double j_x, double j_y);
void	burning_ship(t_fractol *fractol);
double	scale(int pixel, double max, double min, int size);
void	put_pixel(t_fractol *fractol, int x, int y, int color);
int		coloring(int iterations, int max, t_fractol *fractol);
void	hooks_handle(t_fractol *fractol);
void	zoom_at_mouse(t_fractol *fractol, int x, int y, double zoom_factor);
void	mlx_keys(t_fractol *fractol);
void	destroy(t_fractol *fractol);
int		esc(int keycode, t_fractol *fractol);
int		close_b(t_fractol *fractol);
void	close_mlx(t_fractol *fractol);

#endif
