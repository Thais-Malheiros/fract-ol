/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:59:32 by tmalheir          #+#    #+#             */
/*   Updated: 2024/03/04 16:16:03 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

double	ft_scale_real(double src, double adj, double offset, double shift)
{
	return ((src - adj) / WIDHT * (offset - 0) + adj + shift);
}

double	ft_scale_img(double src, double adj, double offset, double shift)
{
	return ((src - adj) / WIDHT * (offset - 0) + adj + shift);
}

double	ft_escape_calc(double side1, double side2)
{
	return (side1 * side1 + side2 * side2);
}
