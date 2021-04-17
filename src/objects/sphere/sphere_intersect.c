/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/17 00:36:39 by msales-a         ###   ########.fr       */
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
	t_intersection *hit)
{
	t_sphere_params	p;
	double			root;

	ray = transform_ray(ray, object.inverse_matrix);
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
	hit->t_object = object;
	hit->t = root;
	hit->point = ray_at(ray, hit->t);
	hit->normal = normalize(minus(hit->point, point(0, 0, 0)));
	hit->front_face = dot(ray.direction, hit->normal) < 0;
	if (!hit->front_face)
		hit->normal = scalar(hit->normal, -1);
	return (true);
}
