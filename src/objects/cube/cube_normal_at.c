/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_normal_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 23:41:27 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static double	max_axis(double x, double y, double z)
{
	if (x > y && x > z)
		return (x);
	if (y > x && y > z)
		return (y);
	return (z);
}

t_vector	cube_normal_at(t_point object_point)
{
	double	max;

	max = max_axis(
		fabs(object_point.x),
		fabs(object_point.y),
		fabs(object_point.z));
	if (max == fabs(object_point.x))
		return (vector(object_point.x, 0, 0));
	if (max == fabs(object_point.y))
		return (vector(0, object_point.y, 0));
	return (vector(0, 0, object_point.z));
}
