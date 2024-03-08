/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_hooks_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:29:25 by tmalheir          #+#    #+#             */
/*   Updated: 2024/03/05 12:21:25 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

static void	ft_zoom_out(t_fractal *fractal)
{
	double	zoom_before;
	double	mouse_x;
	double	mouse_y;

	zoom_before = (*fractal).zoom_range;
	(*fractal).zoom_range += (0.1 * zoom_before);
	mlx_get_mouse_pos(fractal->mlx, &fractal->mouse_x, &fractal->mouse_y);
	mouse_x = ((double)(fractal->mouse_x) / WIDHT - 0.25) * 2.0;
	mouse_y = ((double)(fractal->mouse_y) / HEIGHT - 0.25) * 2.0;
	(*fractal).shift_x -= (mouse_x * 0.1 * zoom_before);
	(*fractal).shift_y -= (mouse_y * 0.1 * zoom_before);
}

static void	ft_zoom_in(t_fractal *fractal)
{
	double	zoom_before;
	double	mouse_x;
	double	mouse_y;

	zoom_before = (*fractal).zoom_range;
	(*fractal).zoom_range -= (0.1 * zoom_before);
	mlx_get_mouse_pos(fractal->mlx, &fractal->mouse_x, &fractal->mouse_y);
	mouse_x = ((double)(fractal->mouse_x) / WIDHT - 0.25) * 2.0;
	mouse_y = ((double)(fractal->mouse_y) / HEIGHT - 0.25) * 2.0;
	(*fractal).shift_x += (mouse_x * 0.1 * zoom_before);
	(*fractal).shift_y += (mouse_y * 0.1 * zoom_before);
}

void	ft_scroll_hook(double delta_x, double delta_y, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (delta_y > 0)
		ft_zoom_in(fractal);
	else if (delta_y < 0)
		ft_zoom_out(fractal);
	if (delta_x < 0)
		ft_zoom_in(fractal);
	else if (delta_x > 0)
		ft_zoom_out(fractal);
}

void	ft_keyhook(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->shift_y -= 0.5;
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->shift_y += 0.5;
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->shift_x += 0.5;
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->shift_x -= 0.5;
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_HOME))
		ft_change_color(fractal);
	ft_fractal_building(fractal);
}
