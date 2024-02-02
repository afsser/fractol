/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:07:00 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/02/02 14:07:01 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	move(t_fractol *st)
{
	double	dx;
	double	dy;

	dx = MOVE_SPEED * (st->xmax - st->xmin) / st->width;
	dy = MOVE_SPEED * (st->ymax - st->ymin) / st->height;
	if (mlx_is_key_down(st->mlx, MLX_KEY_UP))
	{
		st->ymin -= dy;
		st->ymax -= dy;
	}
	if (mlx_is_key_down(st->mlx, MLX_KEY_DOWN))
	{
		st->ymin += dy;
		st->ymax += dy;
	}
	if (mlx_is_key_down(st->mlx, MLX_KEY_LEFT))
	{
		st->xmin -= dx;
		st->xmax -= dx;
	}
	if (mlx_is_key_down(st->mlx, MLX_KEY_RIGHT))
	{
		st->xmin += dx;
		st->xmax += dx;
	}
}

void	zoom(t_fractol *st)
{
	double		zoom_factor;
	double		xrange;
	double		yrange;

	zoom_factor = 0.08;
	xrange = st->xmax - st->xmin;
	yrange = st->ymax - st->ymin;
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_ADD) || mlx_is_key_down(st->mlx,
			MLX_KEY_EQUAL))
	{
		st->xmin = st->xmin + zoom_factor * xrange;
		st->xmax = st->xmax - zoom_factor * xrange;
		st->ymin = st->ymin + zoom_factor * yrange;
		st->ymax = st->ymax - zoom_factor * yrange;
	}
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_SUBTRACT)
		|| mlx_is_key_down(st->mlx, MLX_KEY_MINUS))
	{
		st->xmin = st->xmin - zoom_factor * xrange;
		st->xmax = st->xmax + zoom_factor * xrange;
		st->ymin = st->ymin - zoom_factor * yrange;
		st->ymax = st->ymax + zoom_factor * yrange;
	}
}
