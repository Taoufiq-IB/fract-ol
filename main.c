#include "fractol.h"

int main(void)
{
    t_data  data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fract'ol");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    data.zoom = 1.0;
    data.offset_x = -0.5;
    data.offset_y = 0.0;

    draw_mandelbrot(&data);
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

    mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
    mlx_hook(data.win, 4, 1L << 2, handle_mouse, &data);
    mlx_loop(data.mlx);

    return (0);
}