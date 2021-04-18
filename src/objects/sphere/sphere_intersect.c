/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 17:52:02 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sphere.h"

static t_sphere_params	sphere_params(t_ray ray)
{
	t_sphere_params	p;

	p.oc = minus(ray.origin, point(0, 0, 0));
	p.a = dot(ray.direction, ray.direction);
	p.b = 2 * dot(p.oc, ray.direction);
	p.c = dot(p.oc, p.oc) - 1;
	p.det = p.b * p.b - 4 * p.a * p.c;
	if (p.det < 0)
		return (p);
	p.x1 = (-p.b - sqrt(p.det)) / (2. * p.a);
	p.x2 = (-p.b + sqrt(p.det)) / (2. * p.a);
	return (p);
}

bool	sphere_intersect(
	t_object object,
	t_ray ray,
	t_range range,
	double	*t)
{
	t_sphere_params	p;
	double			root;

	p = sphere_params(ray);
	if (p.det < 0)
		return (false);
	root = p.x1;
	if (root < range.min || range.max < root)
	{
		root = p.x2;
		if (root < range.min || range.max < root)
			return (false);
	}
	*t = root;
	return (true);
}
