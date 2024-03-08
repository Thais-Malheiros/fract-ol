/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:14:32 by tmalheir          #+#    #+#             */
/*   Updated: 2024/03/05 10:37:41 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

int	ft_fractal_parsing(int ac, char *av[], t_fractal *fractal)
{
	if (ac == 2 && !(ft_strncmp(av[1], "mandelbrot", 10)))
		ft_mandelbrot_init(fractal);
	else if (ac == 4 && !(ft_strncmp(av[1], "julia", 5)))
		ft_julia_init(av, fractal);
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
