/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 23:09:53 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./triangle.h"

typedef struct s_triangle_params
{
	t_vector	d_e2;
	double		det;
	t_vector	pl_to_origin;
	double		f;
	double		u;
	t_vector	o_e1;
	double		v;
}				t_triangle_params;


bool	triangle_intersect(
	t_object object,
	t_ray ray,
	t_range range,
	double	*t)
{
	t_triangle			triangle;
	t_triangle_params	p;

	triangle = *(t_triangle*)object.data;
	p.d_e2 = cross(ray.direction, triangle.e2);
	p.det = dot(triangle.e1, p.d_e2);
	if (fabs(p.det) < .000001)
		return (false);
	p.pl_to_origin = minus(ray.origin, triangle.p1);
	p.f = 1. / p.det;
	p.u = p.f * dot(p.pl_to_origin, p.d_e2);
	if (p.u < 0 || 1 < p.u)
		return (false);
	p.o_e1 = cross(p.pl_to_origin, triangle.e1);
	p.v = p.f * dot(ray.direction, p.o_e1);
	if (p.v < 0 || 1 < (p.u + p.v))
		return (false);
	*t = p.f * dot(triangle.e2, p.o_e1);
	if (*t < range.min || range.max < *t)
		return (false);
	return (true);
}
