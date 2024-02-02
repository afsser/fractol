/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:12:14 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/02/02 13:54:23 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	args_error(void)
{
	write(1, "FRACT-OL\n", 9);
	write(1, "\nUSAGE:\n", 8);
	write(1, "\t./fractol [fractal name][params]\n", 34);
	write(1, "\nEXAMPLES:\n", 11);
	write(1, "\tfractol mandelbrot\t\tMandelbrot fractal\n", 40);
	write(1, "\tfractol julia 0.285 +0.01i\tJulia fractal\n", 42);
	write(1, "\tfractol julia -0.4 +0.6i\tAlternate Julia set\n", 46);
	write(1, "\tfractol tricorn\t\t\tTricorn fractal\n", 35);
}

int	check_args(t_fractol st)
{
	if (ft_strcmp(st.name, "mandelbrot") == 0 && st.argc == 2)
		return (1);
	if (ft_strcmp(st.name, "julia") == 0 && st.argc == 4)
		return (1);
	if (ft_strcmp(st.name, "tricorn") == 0 && st.argc == 2)
		return (1);
	return (0);
}

void	ft_hook(void *param)
{
	t_fractol	*st;

	st = (t_fractol *)param;
	if (mlx_is_key_down(st->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(st->mlx);
	move(st);
	mouse_click_drag(st);
	zoom(st);
	mouse_movement(st);
	change_color(st);
	change_fractol(st);
	select_fractol(st);
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;
	mlx_t		*mlx;

	initialize_fractol(&fractol, argc, argv);
	mlx = mlx_init(fractol.width, fractol.height, fractol.name, true);
	fractol.img = mlx_new_image(mlx, fractol.width, fractol.height);
	if (check_args(fractol) && mlx && fractol.img)
	{
		fractol.mlx = mlx;
		select_fractol(&fractol);
		mlx_loop_hook(mlx, ft_hook, &fractol);
		mlx_scroll_hook(mlx, zoom_scroll, &fractol);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		return (EXIT_SUCCESS);
	}
	args_error();
	mlx_close_window(mlx);
	mlx_terminate(mlx);
	return (EXIT_FAILURE);
}
