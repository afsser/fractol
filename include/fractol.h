/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:56:36 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/01/16 17:09:19 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include <../.lib/MLX42/include/MLX42/MLX42.h>

typedef struct s_fractol
{
	char		*name;
	int			argc;
	mlx_image_t	*img;
	mlx_t		*mlx;
	uint32_t	x;
	uint32_t	y;
	int			xpos;
	int			ypos;
	double		xzoom;
	double		yzoom;
	double		xmax;
	double		xmin;
	double		ymax;
	double		ymin;
	double		creal;
	double		cimag;
	int			max_iter;
	int			height;
	int			width;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	double		ccolor;
	bool		active;
}				t_fractol;

void			initialize_fractol(t_fractol *fractol, int nargs, char **args);
void			select_fractol(t_fractol *st);

void			display_mandelbrot(t_fractol *fractol);
// void			display_julia(t_fractol *st);
// void			display_burning_ship(t_fractol *st);
// void			display_tricorn(t_fractol *st);

void			zoom_scroll(double xdelta, double ydelta, void *param);
void			mouse_click_move(t_fractol *fractol);
void			mouse_movement(t_fractol *st);

double			ft_atof(char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strtolower(char *str);

#endif
