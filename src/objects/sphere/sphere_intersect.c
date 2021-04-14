/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/14 09:31:51 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sphere.h"

static t_sphere_params	sphere_params(
	t_sphere sphere,
	t_ray ray)
{
	t_sphere_params	p;

	p.oc = minus(ray.origin, sphere.origin);
	p.a = dot(ray.direction, ray.direction);
	p.b = 2 * dot(p.oc, ray.direction);
	p.c = dot(p.oc, p.oc) - sphere.radius * sphere.radius;
	p.det = p.b * p.b - 4 * p.a * p.c;
	if (p.det < 0)
		return (p);
	p.x1 = (-p.b - sqrt(p.det)) / 2 * p.a;
	p.x1 = (-p.b + sqrt(p.det)) / 2 * p.a;
	return (p);
}

bool	sphere_intersect(
	t_object object,
	t_ray ray,
	t_hit_range range,
	t_intersection *hit)
{
	t_sphere		sphere;
	t_sphere_params	p;
	double			root;

	sphere = *(t_sphere *)object.data;
	p = sphere_params(sphere, ray);
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
	hit->normal = divide(minus(hit->point, sphere.origin), sphere.radius);
	hit->front_face = dot(ray.direction, hit->normal) < 0;
	if (!hit->front_face)
		hit->normal = scalar(hit->normal, -1);
	return (true);
}
