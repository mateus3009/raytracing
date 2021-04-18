/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 10:19:45 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./plane.h"

bool	plane_intersect(
	t_object object,
	t_ray ray,
	t_range range,
	double *t)
{
	t_ray	ray2;

	ray2 = transform_ray(ray, object.inverse_matrix);
	if (fabs(ray2.direction.y) < .0001)
		return (false);
	*t  = (-ray2.origin.y) / ray2.direction.y;
	if (*t < range.min || range.max < *t)
		return (false);
	return (true);
}
