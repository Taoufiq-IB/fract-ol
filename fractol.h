

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    double  zoom;
    double  offset_x;
    double  offset_y;
} t_data;

// Function prototypes
int     mandelbrot(double cr, double ci);
void    draw_mandelbrot(t_data *data);
int     handle_key(int keycode, t_data *data);
int     handle_mouse(int button, int x, int y, t_data *data);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif