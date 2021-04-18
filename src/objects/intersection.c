/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 09:02:19 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 17:53:54 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_intersection	intersection(t_object object, t_ray world_ray, double t)
{
	t_intersection	hit;

	hit.ray = world_ray;
	hit.object = object;
	hit.t = t;
	hit.point = ray_at(world_ray, t);
	hit.normal = normal_at(object, hit.point);
	hit.front_face = dot(world_ray.direction, hit.normal) < 0;
	if (!hit.front_face)
		hit.normal = scalar(hit.normal, -1);
	return (hit);
}
