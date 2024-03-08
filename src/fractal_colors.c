/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:53:03 by tmalheir          #+#    #+#             */
/*   Updated: 2024/03/05 10:34:27 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

uint32_t	ft_bernstein_poly(uint32_t iter_nb, t_fractal *fractal)
{
	double	t;
	int32_t	color;
	int32_t	poly[3];
	t_color	rgb;

	rgb = fractal->channel;
	t = 1.0 * iter_nb / ITERATIONS;
	poly[0] = 255 * 9.0 * t * (1 - t) * (1 - t) * (1 - t);
	poly[1] = 255 * 17.0 * t * t * (1 - t) * (1 - t);
	poly[2] = 255 * 12.0 * t * t * t * (1 - t);
	color = ft_get_rgba(poly[rgb.r], poly[rgb.g], poly[rgb.b], 255);
	return (color);
}

int32_t	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	ft_color(int iter_nb, t_fractal *fractal)
{
	if (iter_nb == ITERATIONS)
		fractal->color = ft_get_rgba(0x00, 0x00, 0x00, 0xFF);
	else
		fractal->color = ft_bernstein_poly(iter_nb, fractal);
	return (fractal->color);
}
