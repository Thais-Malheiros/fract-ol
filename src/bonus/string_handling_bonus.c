/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handling_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:40:53 by tmalheir          #+#    #+#             */
/*   Updated: 2024/03/05 12:21:54 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

/**
 * @brief The atod() function converts the initial portion of the string
 * pointed to by str to double and return the converted value.
 */
double	ft_atod(char *str)
{
	int		sign;
	long	result;
	double	decimal_factor;

	sign = 1;
	result = 0;
	decimal_factor = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (str == NULL)
		return (0);
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
		decimal_factor *= 10;
	}
	return (sign * result / decimal_factor);
}

/**
 * @brief Outputs the string ’str’ to the given file descriptor.
 * */
void	ft_putstr_fd(char *str, int fd)
{
	int	idx;

	if (str)
	{
		idx = 0;
		while (str[idx])
		{
			write(fd, &str[idx], 1);
			idx++;
		}
	}
}

/**
 * @brief Outputs the const char string ’str’ to the given file descriptor.
 * */
void	ft_putconst_fd(char const *str, int fd)
{
	int	idx;

	if (str)
	{
		idx = 0;
		while (str[idx])
		{
			write(fd, &str[idx], 1);
			idx++;
		}
	}
}

/**
 * @brief Compares the first (at most) n bytes of 'str1' and 'str2'.
 * It returns an integer less than, equal to, or greater than zero if str1
 * is found, respectively, to be less than, to match, or be greater than s2.
*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			idx;
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;

	idx = 0;
	ptr_str1 = (unsigned char *)str1;
	ptr_str2 = (unsigned char *)str2;
	while ((ptr_str1[idx] || ptr_str2[idx]) && idx < n)
	{
		if (ptr_str1[idx] < ptr_str2[idx])
			return (-1);
		if (ptr_str1[idx] > ptr_str2[idx])
			return (1);
		idx++;
	}
	return (0);
}
