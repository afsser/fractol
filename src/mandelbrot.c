/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:23:27 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/01/30 21:07:52 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot(double real, double imag, t_fractol *st)
{
	int		iter;
	double	r;
	double	i;
	double	r2;
	double	i2;

	iter = -1;
	r = real;
	i = imag;
	while (++iter < st->max_iter)
	{
		r2 = r * r;
		i2 = i * i;
		if ((r2 + i2) > 10.0)
			return (iter);
		i = 2 * r * i + imag;
		r = r2 - i2 + real;
	}
	return (st->max_iter);
}

void	mandelbrot_pixel(int iter, t_fractol *st)
{
	int			color;
	double		interpolate;
	t_colors	c;

	interpolate = (double)iter / (double)st->max_iter;
	c.smooth = pow(interpolate, 0.3);
	init_color(&c);
	if (interpolate < 0.05)
		color = st->ccolor * interpolate_color(c.col2, c.col1, st, c);
	if (interpolate >= 0.05 && interpolate < 0.15)
		color = st->ccolor * interpolate_color(c.col1, c.col2, st, c);
	if (interpolate >= 0.15 && interpolate < 0.45)
		color = st->ccolor * interpolate_color(c.col2, c.col3, st, c);
	if (interpolate >= 0.45 && interpolate < 0.85)
		color = st->ccolor * interpolate_color(c.col3, c.col4, st, c);
	if (interpolate >= 0.85)
		color = st->ccolor * interpolate_color(c.col4, c.col5, st, c);
	mlx_put_pixel(st->img, st->x, st->y, color);
}

void	display_mandelbrot(t_fractol *st)
{
	int		width;
	int		heigth;
	int		iter;
	double	real;
	double	imag;

	st->x = 0;
	width = (st->img->width - 1);
	heigth = (st->img->height - 1);
	while (st->x < st->img->width)
	{
		st->y = 0;
		while (st->y < st->img->height)
		{
			real = st->xmin + st->x * (st->xmax - st->xmin) / width;
			imag = st->ymin + st->y * (st->ymax - st->ymin) / heigth;
			iter = mandelbrot(real, imag, st);
			mandelbrot_pixel(iter, st);
			st->y++;
		}
		st->x++;
	}
	mlx_image_to_window(st->mlx, st->img, 0, 0);
}
