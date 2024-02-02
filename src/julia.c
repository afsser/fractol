/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:41:09 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/02/02 14:08:25 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	julia(double real, double imag, t_fractol *st)
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
		if ((r2 + i2) > 6.0)
			return (iter);
		i = 2 * r * i + st->cimag;
		r = r2 - i2 + st->creal;
	}
	return (st->max_iter);
}

void	julia_pixel(int iter, t_fractol *st)
{
	int			color;
	double		interpolate;
	t_colors	c;

	interpolate = (double)iter / (double)st->max_iter;
	c.smooth = pow(interpolate, 0.762);
	init_color(&c);
	if (interpolate < 0.3)
		color = st->ccolor * interpolate_color(c.col1, c.col2, st, c);
	if (interpolate >= 0.3 && interpolate < 0.4)
		color = st->ccolor * interpolate_color(c.col2, c.col3, st, c);
	if (interpolate >= 0.4 && interpolate < 0.5)
		color = st->ccolor * interpolate_color(c.col3, c.col4, st, c);
	if (interpolate >= 0.5 && interpolate < 0.6)
		color = st->ccolor * interpolate_color(c.col4, c.col3, st, c);
	if (interpolate >= 0.6 && interpolate < 0.7)
		color = st->ccolor * interpolate_color(c.col3, c.col5, st, c);
	if (interpolate >= 0.7 && interpolate < 0.8)
		color = st->ccolor * interpolate_color(c.col5, c.col3, st, c);
	if (interpolate >= 0.8 && interpolate < 0.9)
		color = st->ccolor * interpolate_color(c.col4, c.col3, st, c);
	if (interpolate >= 0.9)
		color = st->ccolor * interpolate_color(c.col3, c.col5, st, c);
	mlx_put_pixel(st->img, st->x, st->y, color);
}

void	display_julia(t_fractol *st)
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
			iter = julia(real, imag, st);
			julia_pixel(iter, st);
			st->y++;
		}
		st->x++;
	}
	mlx_image_to_window(st->mlx, st->img, 0, 0);
}
