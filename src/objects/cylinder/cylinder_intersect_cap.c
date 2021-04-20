/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect_cap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 09:53:31 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

static bool	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + ray.direction.x * t;
	z = ray.origin.z + ray.direction.z * t;
	return (x * x + z * z <= 1);
}

bool		cylinder_intersect_cap(
	t_object object,
	t_ray ray,
	t_range range,
	double *t)
{
	bool		is_valid;
	t_cylinder	c;
	double		root;

	*t = INFINITY;
	is_valid = false;
	c = *(t_cylinder*)object.data;
	if (!c.closed || fabs(ray.direction.y) < .0001)
		return (false);
	root = (c.min - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, root))
	{
		*t = root;
		is_valid = true;
	}
	root = (c.max - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, root) &&  root < *t)
	{
		*t = root;
		is_valid = true;
	}
	return (is_valid && range.min < *t && *t < range.max);
}
