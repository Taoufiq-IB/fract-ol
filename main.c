
#include "fractol.h"

void    draw_fractol(t_fractol *fractol, char *name)
{
    if (ft_strcmp(name, "mandelbrot") == 0)
        mandelbrot(fractol);
    else
        julia(fractol, fractol->x ,fractol->y);
}

static int	window_init(t_fractol *fractol)
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
	draw_fractol(fractol, fractol->name);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	hooks_handle(fractol);
	close_mlx(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}

static void    usage_error(void)
{
    ft_putstr_fd("Usage:\n./fractol mandelbrot\n", 2);
    ft_putstr_fd("./fractol ./julia <real> <img>\n", 2);
    exit(1);
}

static int isvalid_num(char *s)
{
    int i;
    int point;

    i = 0;
    point = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    while (s[i])
    {
        if (s[i] != '.' && (s[i] < '0' || s[i] > '9'))
            return (1);
        if (s[i] == '.')
            point++;
        i++;
    }
    if (point > 1)
        return (1);
    return (0);
}

static void    argument_parsing(int argc, char **argv, t_fractol *fractol)
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
        if (ft_atod(argv[2]) <= 2 || ft_atod(argv[2]) >= -2 || ft_atod(argv[3]) <= 2
            || ft_atod(argv[3]) >= -2)
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

int main(int argc, char **argv) 
{
    t_fractol fractol;

    argument_parsing(argc, argv, &fractol);
    fractol.mlx = mlx_init();
    if (window_init(&fractol) != 0)
    {
        ft_putstr_fd("something is off\n", 2);
        exit(1);
    }
    return (0);
}
