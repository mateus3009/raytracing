/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect_cap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:29:55 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 16:38:51 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

static bool	check_cap(t_ray ray, double t, t_range range, double radius)
{
	double	x;
	double	z;

	x = ray.origin.x + ray.direction.x * t;
	z = ray.origin.z + ray.direction.z * t;
	return ((x * x + z * z <= fabs(radius))
		&& range.min < t && t < range.max);
}

bool	cone_intersect_cap(
	t_object object,
	t_ray ray,
	t_range range,
	double *t)
{
	bool	is_valid;
	t_cone	c;
	double	root;

	*t = INFINITY;
	is_valid = false;
	c = *(t_cone *)object.data;
	if (!c.closed || fabs(ray.direction.y) < .0001)
		return (false);
	root = (c.min - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, root, range, c.min))
	{
		*t = root;
		is_valid = true;
	}
	root = (c.max - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, root, range, c.max) && root < *t)
	{
		*t = root;
		is_valid = true;
	}
	return (is_valid && range.min < *t && *t < range.max);
}
