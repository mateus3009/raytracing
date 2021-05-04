/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 19:44:01 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"

bool	disk_intersect(
	t_object object,
	t_ray ray,
	t_range range,
	double *t)
{
	double	x;
	double	z;

	if (fabs(ray.direction.y) < .0001)
		return (false);
	*t = -ray.origin.y / ray.direction.y;
	if (*t < 0 || *t < range.min || range.max < *t)
		return (false);
	x = ray.origin.x + ray.direction.x * *t;
	z = ray.origin.z + ray.direction.z * *t;
	return (x * x + z * z <= 1);
}
