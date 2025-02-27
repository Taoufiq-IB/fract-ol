
#include "fractol.h"

double	scale(int pixel, double max, double min, int size)
{
	return (min + (((max - min) * pixel) / size));
}

void put_pixel(t_fractol *fractol, int x, int y, int color) 
{
    char *dst;

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) 
	{
        dst = fractol->addr + (y * fractol->line_length + x * (fractol->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
    }
}

int	coloring(int i, int max)
{
	int	r;
	int	g;
	int	b;

	if (i == max)
		return (0x000000);
	r = (i * 5 + 50) % 256;
	g = (i * 3 + 100) % 256;
	b = (i * 7 + 150) % 256;
	return (r << 16 | g << 8 | b);
}

static int	mouse_wheel(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractol->zoom *= 1.1;
	else if (button == 5)
		fractol->zoom *= 0.9;
	else
		return (0);
	if (ft_strcmp(fractol->name, "mandelbrot") == 0)
		draw_fractol(fractol, "mandelbrot");
	else if (ft_strcmp(fractol->name, "julia") == 0)
		draw_fractol(fractol, "julia");
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	return (0);
}

void	hooks_handle(t_fractol *fractol)
{
	mlx_mouse_hook(fractol->win, mouse_wheel, fractol);
}

