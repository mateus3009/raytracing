/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 08:06:49 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_range	check_axis(double origin, double direction)
{
	double	min;
	double	max;

	min = (-1 - origin) / direction;
	max = (1 - origin) / direction;
	if (min > max)
		return ((t_range){.min = max, .max = min});
	return ((t_range){.min = min, .max = max});
}

static double	min_t(double a, double b, double c)
{
	if (a < b && a < c)
		return (a);
	if (b < a && b < c)
		return (b);
	return (c);
}

static double	max_t(double a, double b, double c)
{
	if (a > b && a > c)
		return (a);
	if (b > a && b > c)
		return (b);
	return (c);
}

bool	cube_intersect(
	t_object object,
	t_ray ray,
	t_range range,
	double *t)
{
	t_range	x;
	t_range	y;
	t_range	z;
	double	min;
	double	max;

	x = check_axis(ray.origin.x, ray.direction.x);
	y = check_axis(ray.origin.y, ray.direction.y);
	z = check_axis(ray.origin.z, ray.direction.z);
	min = max_t(x.min, y.min, z.min);
	max = min_t(x.max, y.max, z.max);
	if (min > max || min < range.min || range.max < min)
		return (false);
	*t = min;
	return (true);
}
