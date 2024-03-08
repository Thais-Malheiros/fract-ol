/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:17:44 by tmalheir          #+#    #+#             */
/*   Updated: 2024/03/05 12:21:31 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

void	ft_bship_init(t_fractal *fractal)
{
	fractal->type = BURNING_SHIP;
	fractal->adjusted_x = -2.0;
	fractal->adjusted_y = -2.0;
	fractal->escape_value = 4.0;
	fractal->zoom_range = 4.0;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->channel.r = 0;
	fractal->channel.g = 1;
	fractal->channel.b = 2;
}

void	ft_julia_init(char *av[], t_fractal *fractal)
{
	fractal->type = JULIA;
	fractal->adjusted_x = -2.0;
	fractal->adjusted_y = -2.0;
	fractal->escape_value = 4.0;
	fractal->zoom_range = 4.0;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->param_1 = ft_atod(av[2]);
	fractal->param_2 = ft_atod(av[3]);
	fractal->channel.r = 0;
	fractal->channel.g = 1;
	fractal->channel.b = 2;
}

void	ft_mandelbrot_init(t_fractal *fractal)
{
	fractal->type = MANDELBROT;
	fractal->adjusted_x = -2.0;
	fractal->adjusted_y = -2.0;
	fractal->escape_value = 4.0;
	fractal->zoom_range = 4.0;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->channel.r = 0;
	fractal->channel.g = 1;
	fractal->channel.b = 2;
}

int	ft_fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDHT, HEIGHT, "Fract'ol", false);
	if (fractal->mlx == NULL)
	{
		ft_putconst_fd(mlx_strerror(mlx_errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	fractal->image = mlx_new_image(fractal->mlx, WIDHT, HEIGHT);
	if (fractal->image == NULL
		|| (mlx_image_to_window(fractal->mlx, fractal->image, 0, 0)) == -1)
	{
		mlx_close_window(fractal->mlx);
		ft_putconst_fd(mlx_strerror(mlx_errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
