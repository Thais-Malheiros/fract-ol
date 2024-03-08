/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_building_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:57:11 by tmalheir          #+#    #+#             */
/*   Updated: 2024/03/05 12:21:12 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

int	ft_bship_iterations(int x, int y, t_fractal fractal)
{
	t_complex	nbr;
	double		temp;
	int			idx;

	nbr.z_real = 0.0;
	nbr.z_img = 0.0;
	nbr.c_real = ft_scale_real(x, fractal.adjusted_x, \
				fractal.zoom_range, fractal.shift_x);
	nbr.c_img = ft_scale_img(y, fractal.adjusted_y, \
				fractal.zoom_range, fractal.shift_y);
	idx = 0;
	while ((idx < ITERATIONS)
		&& ft_escape_calc(nbr.z_real, nbr.z_img) <= fractal.escape_value)
	{
		temp = nbr.z_real * nbr.z_real - nbr.z_img * nbr.z_img + nbr.c_real;
		nbr.z_img = fabs(2.0 * nbr.z_real * nbr.z_img) + nbr.c_img;
		nbr.z_real = temp;
		idx++;
	}
	return (idx);
}

int	ft_julia_iterations(int x, int y, t_fractal fractal)
{
	t_complex	nbr;
	double		temp;
	int			idx;

	nbr.z_real = ft_scale_real(x, fractal.adjusted_x, \
				fractal.zoom_range, fractal.shift_x);
	nbr.z_img = ft_scale_img(y, fractal.adjusted_y, \
				fractal.zoom_range, fractal.shift_y);
	nbr.c_real = fractal.param_1;
	nbr.c_img = fractal.param_2;
	idx = 0;
	while ((idx < ITERATIONS)
		&& ft_escape_calc(nbr.z_real, nbr.z_img) <= fractal.escape_value)
	{
		temp = nbr.z_real * nbr.z_real - nbr.z_img * nbr.z_img + nbr.c_real;
		nbr.z_img = 2.0 * nbr.z_real * nbr.z_img + nbr.c_img;
		nbr.z_real = temp;
		idx++;
	}
	return (idx);
}

int	ft_mandelbrot_iterations(int x, int y, t_fractal fractal)
{
	t_complex	nbr;
	double		temp;
	int			idx;

	nbr.z_real = 0;
	nbr.z_img = 0;
	nbr.c_real = ft_scale_real(x, fractal.adjusted_x, \
					fractal.zoom_range, fractal.shift_x);
	nbr.c_img = ft_scale_img(y, fractal.adjusted_y, \
					fractal.zoom_range, fractal.shift_y);
	idx = 0;
	while ((idx < ITERATIONS)
		&& ft_escape_calc(nbr.z_real, nbr.z_img) <= fractal.escape_value)
	{
		temp = nbr.z_real * nbr.z_real - nbr.z_img * nbr.z_img + nbr.c_real;
		nbr.z_img = 2.0 * nbr.z_real * nbr.z_img + nbr.c_img;
		nbr.z_real = temp;
		idx++;
	}
	return (idx);
}

void	ft_fractal_building(void *param)
{
	t_fractal	*fractal;
	uint32_t	color;
	int			x_axis;
	int			y_axis;
	int			iter_nb;

	fractal = (t_fractal *)param;
	y_axis = 0;
	while (y_axis < HEIGHT)
	{
		x_axis = 0;
		while (x_axis < WIDHT)
		{
			if (fractal->type == MANDELBROT)
				iter_nb = ft_mandelbrot_iterations(x_axis, y_axis, *fractal);
			else if (fractal->type == JULIA)
				iter_nb = ft_julia_iterations(x_axis, y_axis, *fractal);
			else if (fractal->type == BURNING_SHIP)
				iter_nb = ft_bship_iterations(x_axis, y_axis, *fractal);
			color = ft_color(iter_nb, fractal);
			mlx_put_pixel(fractal->image, x_axis, y_axis, color);
			++x_axis;
		}
		++y_axis;
	}
}
