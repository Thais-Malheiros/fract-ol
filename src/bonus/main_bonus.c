/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:04:43 by tmalheir          #+#    #+#             */
/*   Updated: 2024/03/05 12:21:45 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

int	main(int ac, char *av[])
{
	t_fractal	fractal;

	if (ft_fractal_parsing(ac, av, &fractal))
		return (EXIT_FAILURE);
	ft_fractal_init(&fractal);
	mlx_loop_hook(fractal.mlx, ft_keyhook, &fractal);
	mlx_scroll_hook(fractal.mlx, ft_scroll_hook, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
