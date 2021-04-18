/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/17 21:01:47 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./plane.h"

bool	plane_intersect(
	t_object object,
	t_ray ray,
	t_range range,
	t_intersection *hit)
{
	t_ray	ray2;

	ray2 = transform_ray(ray, object.inverse_matrix);
	if (fabs(ray2.direction.y) < .0001)
		return (false);
	hit->ray = ray;
	hit->object = object;
	hit->t = -ray2.origin.y / ray2.direction.y;
	hit->point = ray_at(ray, hit->t);
	hit->normal = normalize(matrix_product(matrix_transpose(object.inverse_matrix), vector(0, 1, 0)));
	hit->normal.w = 0;
	hit->front_face = dot(ray.direction, hit->normal) < 0;
	if (!hit->front_face)
		hit->normal = scalar(hit->normal, -1);
	return (true);
}
