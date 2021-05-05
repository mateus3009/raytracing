/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:03:35 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 07:49:16 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "./../../lib/minilibx-linux/mlx.h"
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
int		count_strtoken(char	**tokens);
void	free_strtoken(char	***tokens);
void	fatal(char	*msg);

#endif
