/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 00:39:06 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

bool	cylinder(t_object **obj, t_cylinder_build params)
{
	t_cylinder	*data;

	*obj = object(sizeof(t_cylinder));
	if (!*obj)
		return (false);
	(*obj)->intersect = cylinder_intersect;
	(*obj)->normal_at = cylinder_normal_at;
	(*obj)->color = params.color;
	data = ((t_cylinder*)(*obj)->data);
	data->min = params.height_min;
	data->max = params.height_max;
	data->closed = params.is_closed;
	add_transformation(*obj,
		scaling(params.radius, params.radius, params.radius));
	add_transformation(*obj,
		translate(params.origin.x, params.origin.y, params.origin.z));
	add_transformation(*obj,
		from_to_rotation(vector(0, 1, 0), params.direction));
	return (true);
}
