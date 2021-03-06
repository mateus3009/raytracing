/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:03:35 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 08:38:05 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "mlx.h"
# include "./../../lib/libft/srcs/libft.h"

# include <math.h>
# include <stdio.h>
# include <float.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include <pthread.h>

# define PI 3.14159265358979323846

extern unsigned long long int	g_seed;

double	degrees_to_radians(double degrees);
double	radians_to_degrees(double radians);
double	ft_rand(void);
void	ft_srand(unsigned long long int seed);
double	clamp(double value, double min, double max);
double	ft_rand_range(double min, double max);
void	free_strtoken(char	***tokens, int argc);
void	fatal(char	*msg);

#endif
