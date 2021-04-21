/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 09:48:54 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

bool	cone_intersect(
	t_object object,
	t_ray ray,
	t_range range,
	double *t)
{
	double	body;
	double	cap;

	if (!cone_intersect_body(object, ray, range, &body))
		body = INFINITY;
	if (!cone_intersect_cap(object, ray, range, &cap))
		cap = INFINITY;
	if (body < cap)
		*t = body;
	else
		*t = cap;
	return (!isinf(*t));
}
