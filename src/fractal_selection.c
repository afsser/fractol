/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:41:51 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/01/30 21:25:18 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	initialize_fractol(t_fractol *fractol, int nargs, char **args)
{
	fractol->name = ft_strtolower(args[1]);
	if (fractol->name == NULL)
		fractol->name = "error";
	fractol->argc = nargs;
	fractol->height = 800;
	fractol->width = 800;
	fractol->max_iter = 100;
	fractol->xmax = 1.0;
	fractol->xmin = -2.0;
	fractol->ymax = 1.5;
	fractol->ymin = -1.5;
	fractol->x = 0;
	fractol->y = 0;
	fractol->ccolor = 1;
	fractol->active = 0;
	fractol->xstart = 0;
	fractol->ystart = 0;
	if (ft_strcmp(fractol->name, "julia") == 0 && fractol->argc == 4)
	{
		fractol->xmax = 2.0;
		fractol->creal = ft_atof(args[2]);
		fractol->cimag = ft_atof(args[3]);
	}
}

char	*change_fractol(t_fractol *st)
{
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_1))
		return("mandelbrot");
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_2))
	{
		st->creal = 0.285;
		st->cimag = 0.01;
		return("julia");
	}
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_3))
		return("tricorn");
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_4))
	{
		st->creal = -0.123;
		st->cimag = 0.745;
		return("julia");
	}
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_5))
	{
		st->creal = -0.56;
		st->cimag = 0.5;
		return("julia");
	}
	return (st->name);
}

void	select_fractol(t_fractol *st)
{
	st->name = change_fractol(st);
	
	if (ft_strcmp(st->name, "mandelbrot") == 0)
		return (display_mandelbrot(st));
	if (ft_strcmp(st->name, "julia") == 0)
		return (display_julia(st));
	if (ft_strcmp(st->name, "tricorn") == 0)
		return (display_tricorn(st));
	// if (ft_strcmp(st->name, "tricorn") == 0)
	// 	return (display_tricorn(st));
}
