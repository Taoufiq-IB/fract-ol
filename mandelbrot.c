#include "fractol.h"

int mandelbrot(double cr, double ci)
{
    double zr = 0.0;
    double zi = 0.0;
    double temp;
    int iter = 0;

    while (zr * zr + zi * zi <= 4 && iter < MAX_ITER)
    {
        temp = zr * zr - zi * zi + cr;
        zi = 2 * zr * zi + ci;
        zr = temp;
        iter++;
    }
    return iter;
}

void draw_mandelbrot(t_data *data)
{
    int x, y;
    int color;
    double cr, ci;

    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            cr = (x - WIDTH / 2.0) * 4.0 / (WIDTH * data->zoom) + data->offset_x;
            ci = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * data->zoom) + data->offset_y;
            color = mandelbrot(cr, ci);
            my_mlx_pixel_put(data, x, y, color * 0xFFFFFF / MAX_ITER);
        }
    }
}