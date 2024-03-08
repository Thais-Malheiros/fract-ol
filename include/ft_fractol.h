/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:25:12 by tmalheir          #+#    #+#             */
/*   Updated: 2024/03/08 13:28:13 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * @brief Define for code.
 * @param ITERATIONS    -> The number of iterations for the Mandelbrot formula.
 * @param WIDHT         -> Screen widht.
 * @param HEIGHT        -> Screen height.
 * @param ERROR_MESSAGE -> Assists the user.
*/
# define ITERATIONS 200
# define WIDHT 800
# define HEIGHT 800
# define ERROR_MESSAGE "\n**************************** \
						\n       FRACTOL GUIDE \
						\n**************************** \
						\n./fractol \033[0;32mmandelbrot\033[0m \
						\n./fractol \033[0;34mjulia \033[36m0.285 0.01\033[0m \
						\n./fractol \033[0;34mjulia \033[36m0.45 0.1428\033[0m \
						\n./fractol \033[0;34mjulia \033[36m-0.835 -0.232\033[0m \
						\n./fractol \033[0;34mjulia \033[36m−0.7269 0.1889\033[0m \
						\n./fractol \033[0;34mjulia \033[36m0.35 0.35\033[0m \
						\n./fractol \033[0;34mjulia \033[36m0.4 0.4\033[0m \
						\n./fractol \033[0;31mburning_ship\033[0m \
						\n****************************"

/**
 @brief Fractal color set
 */
typedef struct s_color
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}				t_color;

/**
 @brief Fractal ID
 @param mlx         -> Points to the window created by mlx_init.
 @param image       -> Points to the image buffer created by mlx_new_image.
 @param type        -> 0 (mandelbrot), 1 (julia), 2 (burning_ship).
 @param adjusted_x  -> Adjusts the x-axis with the home axis in the mlx window.
 @param adjusted_y  -> Adjusts the y-axis with the home axis in the mlx window.
 @param zoom_range  -> Applied zoom scale.
 @param zoom_move_x -> Moves the fractal along the x-axis.
 @param zoom_move_y -> Moves the fractal along the y-axis.
 @param param_1     -> Julia set first parameter.
 @param param_2     -> Julia set second parameter.
 @param color       -> Final rendering color.
 @param channel     -> RGB channels.
 */
typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			type;
	double		adjusted_x;
	double		adjusted_y;
	double		escape_value;
	double		zoom_range;
	double		shift_x;
	double		shift_y;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		param_1;
	double		param_2;
	int32_t		color;
	t_color		channel;
}				t_fractal;

/**
 @brief Fractal type
 @param MANDELBROT (0).
 @param JULIA (1).
 @param BURNING_SHIP (2).
 */
typedef enum e_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP,
}			t_type;

/**
 @brief Complex number set
*/
typedef struct s_complex
{
	double	c_real;
	double	c_img;
	double	z_real;
	double	z_img;
}				t_complex;

/**
 @brief Initialization function prototypes.
 */
int			ft_fractal_init(t_fractal *fractal);
void		ft_julia_init(char *av[], t_fractal *fractal);
void		ft_mandelbrot_init(t_fractal *fractal);
void		ft_bship_init(t_fractal *fractal);

/**
 @brief Fractal building function prototypes.
 */
void		ft_fractal_building(void *param);
int			ft_fractal_parsing(int ac, char *av[], t_fractal *fractal);
int			ft_julia_iterations(int x, int y, t_fractal fractal);
int			ft_mandelbrot_iterations(int x, int y, t_fractal fractal);
int			ft_bship_iterations(int x, int y, t_fractal fractal);
double		ft_scale_real(double src, double adj, double offset, double shift);
double		ft_scale_img(double src, double adj, double offset, double shift);

/**
 @brief Coloring function prototypes.
 */
int32_t		ft_color(int iter_nb, t_fractal *fractal);
void		ft_change_color(t_fractal	*fractal);
int32_t		ft_get_rgba(int r, int g, int b, int a);
uint32_t	ft_bernstein_poly(uint32_t iter_nb, t_fractal *fractal);

/**
 @brief Math function prototypes.
 */
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		ft_escape_calc(double side1, double side2);

/**
 @brief Hook function prototypes.
 */
void		ft_keyhook(void *param);
void		ft_scroll_hook(double delta_x, double delta_y, void *param);

/**
 @brief String handling function prototypes.
 */
double		ft_atod(char *str);
void		ft_putconst_fd(const char *str, int fd);
void		ft_putstr_fd(char *str, int fd);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
#endif
