/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 19:18:21 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

bool	square_intersect(
	t_object object,
	t_ray ray,
	t_range range,
	double *t)
{
	double	n;

	if (fabs(ray.direction.y) < .0001)
		return (false);
	*t = -ray.origin.y / ray.direction.y;
	if (*t < 0 || *t < range.min || range.max < *t)
		return (false);
	n = ray.origin.x + *t * ray.direction.x;
	if (n < -1 || 1 < n)
		return (false);
	n = ray.origin.z + *t * ray.direction.z;
	if (n < -1 || 1 < n)
		return (false);
	return (true);
}
