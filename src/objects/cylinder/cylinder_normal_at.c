/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 17:14:06 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

t_vector	cylinder_normal_at(void	*data, t_point point)
{
	t_cylinder	cylinder;
	double		distance;

	cylinder = *(t_cylinder*)data;
	distance = point.x * point.x + point.z * point.z;
	if (distance < 1 && point.y >= cylinder.max - .0001)
		return (vector(0, 1, 0));
	if (distance < 1 && point.y <= cylinder.min + .0001)
		return (vector(0, -1, 0));
	return (vector(point.x, 0, point.z));
}
