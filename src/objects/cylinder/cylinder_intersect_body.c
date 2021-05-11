/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect_body.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 07:47:57 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

static void	swap(double *a, double *b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}

static bool	get_roots(t_ray ray, t_range range, t_cylinder_param *p)
{
	p->a = ray.direction.x * ray.direction.x
		+ ray.direction.z * ray.direction.z;
	if (fabs(p->a) < .0001)
		return (false);
	p->b = 2 * ray.origin.x * ray.direction.x
		+ 2 * ray.origin.z * ray.direction.z;
	p->c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	p->d = p->b * p->b - 4 * p->a * p->c;
	if (p->d < 0)
		return (false);
	p->x1 = (-p->b - sqrt(p->d)) / (2. * p->a);
	p->x2 = (-p->b + sqrt(p->d)) / (2. * p->a);
	if (p->x1 > p->x2)
		swap(&p->x1, &p->x2);
	return ((range.min < p->x1 && p->x1 < range.max)
		|| (range.min < p->x2 && p->x2 < range.max));
}

static bool	check_roots(t_cylinder_param_roots a)
{
	bool	valid;
	double	y;

	*a.t = INFINITY;
	valid = false;
	y = a.ray.origin.y + a.p.x1 * a.ray.direction.y;
	if (a.c.min < y && y < a.c.max
		&& a.range.min < a.p.x1 && a.p.x1 < a.range.max)
	{
		valid = true;
		*a.t = a.p.x1;
	}
	y = a.ray.origin.y + a.p.x2 * a.ray.direction.y;
	if (a.c.min < y && y < a.c.max && a.p.x2 < *a.t
		&& a.range.min < a.p.x2 && a.p.x2 < a.range.max)
	{
		valid = true;
		*a.t = a.p.x2;
	}
	return (valid);
}

bool	cylinder_intersect_body(
	t_object object,
	t_ray ray,
	t_range range,
	double *t)
{
	t_cylinder			c;
	t_cylinder_param	p;

	c = *(t_cylinder *)object.data;
	if (!get_roots(ray, range, &p))
		return (false);
	if (!check_roots((t_cylinder_param_roots){
			.ray = ray,
			.p = p,
			.c = c,
			.t = t,
			.range = range}))
		return (false);
	return (true);
}
