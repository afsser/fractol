#include "../include/fractol.h"

void	init_color(t_colors *colors)
{
	colors->col1 = 0x122368;
	colors->col2 = 0x321d7c;
	colors->col3 = 0x21488a;
	colors->col4 = 0x82d8e9;
	colors->col5 = 0x000000;
}

int	interpolate_color(int col1, int col2, t_fractol *st, t_colors c)
{
	c.r1 = (col1 >> 16) & 0xFF;
	c.g1 = (col1 >> 8) & 0xFF;
	c.b1 = col1 & 0xFF;
	c.r2 = (col2 >> 16) & 0xFF;
	c.g2 = (col2 >> 8) & 0xFF;
	c.b2 = col2 & 0xFF;
	st->r = (int)(c.r1 + c.smooth * (c.r2 - c.r1));
	st->g = (int)(c.g1 + c.smooth * (c.g2 - c.g1));
	st->b = (int)(c.b1 + c.smooth * (c.b2 - c.b1));
	return ((st->r << 24) | (st->g << 16) | (st->b << 8) | 255);
}

void	change_color(t_fractol *st)
{
	double	zoom;
	double	x;
	double	y;

	if (mlx_is_key_down(st->mlx, MLX_KEY_0))
		st->ccolor = 1.1;
	if (mlx_is_key_down(st->mlx, MLX_KEY_1))
		st->ccolor = 1.0;
	if (mlx_is_key_down(st->mlx, MLX_KEY_2))
		st->ccolor = 0.97;
	if (mlx_is_key_down(st->mlx, MLX_KEY_3))
		st->ccolor = 0.95;
	if (mlx_is_key_down(st->mlx, MLX_KEY_4))
		st->ccolor = 0.92;
	if (mlx_is_key_down(st->mlx, MLX_KEY_5) || st->active)
	{
		if (mlx_is_key_down(st->mlx, MLX_KEY_5))
			st->active = !st->active;
		zoom = (st->xmax - st->xmin) / (st->ymax - st->ymin);
		x = (st->xmax - st->xmin);
		y = (st->ymin - st->xmin);
		st->ccolor = (zoom * 0.333 + x * 0.333 + y * 0.333);
	}
}