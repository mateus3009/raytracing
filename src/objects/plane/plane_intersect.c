/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 22:13:13 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./plane.h"

bool	plane_intersect(
	t_object object,
	t_ray ray,
	t_range range,
	double *t)
{
	if (fabs(ray.direction.y) < .0001)
		return (false);
	*t = (-ray.origin.y) / ray.direction.y;
	if (*t < range.min || range.max < *t)
		return (false);
	return (true);
}
