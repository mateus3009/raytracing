/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 08:46:20 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 09:58:01 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

bool	intersect(
	t_object obj,
	t_ray world_ray,
	t_range range,
	t_intersection *hit)
{
	t_ray	object_ray;
	double	t;

	object_ray = transform_ray(world_ray, obj.inverse_matrix);
	if (!obj.intersect(obj, object_ray, range, &t))
		return (false);
	*hit = intersection(obj, world_ray, t);
	return (true);
}
