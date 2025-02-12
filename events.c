#include "fractol.h"

int handle_key(int keycode, t_data *data)
{
    if (keycode == 53) // ESC key
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return (0);
}

int handle_mouse(int button, int x, int y, t_data *data)
{
    if (button == 4) // Mouse wheel up (zoom in)
    {
        data->zoom *= 1.1;
    }
    else if (button == 5) // Mouse wheel down (zoom out)
    {
        data->zoom /= 1.1;
    }
    draw_mandelbrot(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}