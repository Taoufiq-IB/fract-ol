

#include "fractol_bonus.h"

void    color_shifting(t_fractol *fractol, int i)
{
    fractol->r += i;
    fractol->g += i;
    fractol->b += i;
}

void	zoom_at_mouse(t_fractol *fractol, int x, int y, double zoom_factor)
{
    double	mouse_real; 
	double	mouse_imag;

    mouse_real = scale(x, 2.0, -2.0, WIDTH) * fractol->zoom + fractol->offset_x;
    mouse_imag = scale(y, 2.0, -2.0, HEIGHT) * fractol->zoom + fractol->offset_y;
    fractol->zoom *= zoom_factor;
    fractol->offset_x = mouse_real - (scale(x, 2.0, -2.0, WIDTH)) * fractol->zoom;
    fractol->offset_y = mouse_imag - (scale(y, 2.0, -2.0, HEIGHT)) * fractol->zoom;
}

int handle_key(int keycode, t_fractol *fractol)
{
	if (keycode == 65362)
		fractol->offset_y -= 0.5 * fractol->zoom;
	else if (keycode == 65364)
		fractol->offset_y += 0.5 * fractol->zoom;
	else if (keycode == 65361)
		fractol->offset_x -= 0.5 * fractol->zoom;
    else if (keycode == 65363)
        fractol->offset_x += 0.5 * fractol->zoom;
    else if (keycode == 61)
        color_shifting(fractol, 1);
    else if (keycode == 45)
        color_shifting(fractol, -1);
    burning_ship(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
    return (0);
}

void	mlx_keys(t_fractol *fractol)
{
	mlx_key_hook(fractol->win, handle_key, fractol);
}
