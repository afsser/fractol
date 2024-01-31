/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:06:21 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/01/30 21:05:23 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	move(t_fractol *st, int dx, int dy)
{
		st->xmin -= dx * ((st->xmax - st->xmin) / st->width);
		st->xmax -= dx * ((st->xmax - st->xmin) / st->width);
		st->ymin -= dy * ((st->ymax - st->ymin) / st->height);
		st->ymax -= dy * ((st->ymax - st->ymin) / st->height);
}

void	mouse_click_move(t_fractol *st)
{
	int	dx;
	int	dy;

	if (mlx_is_mouse_down(st->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		mlx_get_mouse_pos(st->mlx, &st->xpos, &st->ypos);
		if (st->xstart == 0 && st->ystart == 0)
		{
			st->xstart = st->xpos;
			st->ystart = st->ypos;
		}
		dx = st->xpos - st->xstart;
		dy = st->ypos - st->ystart;
		if (sqrt(dx * dx + dy * dy) > 0)
		{
			dx = dx * 40 / sqrt(dx * dx + dy * dy);
			dy = dy * 40 / sqrt(dx * dx + dy * dy);
		}
		move(st, dx, dy);
	}
	else
	{
		st->xstart = 0;
		st->ystart = 0;
	}
}

void	zoom_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*st;
	double		zoom_factor;

	st = param;
	xdelta = 0;
	zoom_factor = 1.075;
	mlx_get_mouse_pos(st->mlx, &st->xpos, &st->ypos);
	st->xzoom = st->xmin + st->xpos * ((st->xmax - st->xmin) / st->width);
	st->yzoom = st->ymin + st->ypos * ((st->ymax - st->ymin) / st->height);
	if (ydelta > 0)
	{
		st->xmin = st->xzoom - (1.0 / zoom_factor) * (st->xzoom - st->xmin);
		st->xmax = st->xzoom + (1.0 / zoom_factor) * (st->xmax - st->xzoom);
		st->ymin = st->yzoom - (1.0 / zoom_factor) * (st->yzoom - st->ymin);
		st->ymax = st->yzoom + (1.0 / zoom_factor) * (st->ymax - st->yzoom);
	}
	if (ydelta < 0)
	{
		st->xmin = st->xzoom - zoom_factor * (st->xzoom - st->xmin);
		st->xmax = st->xzoom + zoom_factor * (st->xmax - st->xzoom);
		st->ymin = st->yzoom - zoom_factor * (st->yzoom - st->ymin);
		st->ymax = st->yzoom + zoom_factor * (st->ymax - st->yzoom);
	}
}

void	mouse_movement(t_fractol *st)
{
	double	x_range;
	double	y_range;
	double	normalized_x;
	double	normalized_y;

	if (mlx_is_key_down(st->mlx, MLX_KEY_LEFT_SHIFT))
	{
		mlx_get_mouse_pos(st->mlx, &st->xpos, &st->ypos);
		x_range = st->xmax - st->xmin;
		y_range = st->ymax - st->ymin;
		normalized_x = (double)st->xpos / (double)st->width;
		normalized_y = (double)st->ypos / (double)st->height;
		st->creal = st->xmin + (normalized_x * 0.85) * x_range;
		st->cimag = st->ymin + (normalized_y * 0.85) * y_range;
	}
}
