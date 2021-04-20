/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect_body.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 08:57:06 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

static void	swap(double *a, double *b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}

static bool	get_roots(t_ray ray, t_range range, t_cone_param *p)
{
	p->a = ray.direction.x * ray.direction.x
		- ray.direction.y * ray.direction.y
		+ ray.direction.z * ray.direction.z;
	p->b = 2  * ray.origin.x * ray.direction.x
		- 2 * ray.origin.y * ray.direction.y
		+ 2 * ray.origin.z * ray.direction.z;
	if (fabs(p->a) < .0001 && fabs(p->b) < 0.0001)
		return (false);
	p->c = ray.origin.x * ray.origin.x
		- ray.origin.y * ray.origin.y
		+ ray.origin.z * ray.origin.z;
	if (fabs(p->a) < .0001)
	{
		p->x1 = (p->c * -1) / (2. * p->b);
		p->x2 = -p->x1;
		return (true);
	}
	p->d = p->b * p->b - 4 * p->a * p->c;
	if (p->d < 0)
		return (false);
	p->x1 = (-p->b - sqrt(p->d)) / (2. * p->a);
	p->x2 = (-p->b + sqrt(p->d)) / (2. * p->a);
	if (p->x1 > p->x2)
		swap(&p->x1, &p->x2);
	return ((range.min < p->x1 && p->x1 < range.max) || (range.min < p->x2 && p->x2 < range.max));
}

static bool check_roots(t_ray ray, t_cone_param p, t_cone c, double *t)
{
	bool	valid;
	double	y;

	*t = INFINITY;
	valid = false;
	y = ray.origin.y + p.x1 * ray.direction.y;
	if (c.min < y && y < c.max)
	{
		valid = true;
		*t = p.x1;
	}
	y = ray.origin.y + p.x2 * ray.direction.y;
	if (c.min < y && y < c.max && p.x2 < *t)
	{
		valid = true;
		*t = p.x2;
	}
	return (valid);
}

bool		cone_intersect_body(
	t_object object,
	t_ray ray,
	t_range range,
	double *t)
{
	t_cone			c;
	t_cone_param	p;

	c = *(t_cone*)object.data;
	if (!get_roots(ray, range, &p))
		return (false);
	if(!check_roots(ray, p, c, t))
		return (false);
	return (true);
}
