
#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while ((str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

static int	integral_part(char **s)
{
	int	res;

	res = 0;
	while (**s && **s != '.')
	{
		res = res * 10 + (**s - 48);
		(*s)++;
	}
	return (res);
}

static	double	fractional_part(char *s)
{
	double	frac;
	double	res;

	frac = 1;
	res = 0;
	if (*s)
		s++;
	while (*s)
	{
		frac /= 10;
		res += (*s - 48) * frac;
		s++;
	}
	return (res);
}

double	ft_atod(char *s)
{
	int		int_part;
	double	frac_part;
	int		sign;

	sign = 1;
	while (*s && (*s == ' ' || (*s >= 9 && *s <= 13)))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	int_part = integral_part(&s);
	frac_part = fractional_part(s);
	return ((int_part + frac_part) * sign);
}
