/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_normal_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 17:14:06 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

t_vector	cone_normal_at(void	*data, t_point point)
{
	t_cone	cone;
	double	distance;

	cone = *(t_cone *)data;
	distance = point.x * point.x + point.z * point.z;
	if (distance < 1 && point.y >= cone.max - .0001)
		return (vector(0, 1, 0));
	if (distance < 1 && point.y <= cone.min + .0001)
		return (vector(0, -1, 0));
	distance = sqrt(point.x * point.x + point.z * point.z);
	if (point.y > 0)
		distance = -distance;
	return (vector(point.x, distance, point.z));
}
