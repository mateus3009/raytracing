/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:38:56 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

bool	cone(t_object **obj, t_cone_build params)
{
	t_cone	*data;

	*obj = object(sizeof(t_cone));
	if (!*obj)
		return (false);
	(*obj)->intersect = cone_intersect;
	(*obj)->normal_at = cone_normal_at;
	(*obj)->material.color = params.color;
	data = ((t_cone *)(*obj)->data);
	data->min = params.height_min;
	data->max = params.height_max;
	data->closed = params.is_closed;
	add_transformation(*obj,
		translate(params.origin.x, params.origin.y, params.origin.z));
	add_transformation(*obj,
		from_to_rotation(vector(0, 1, 0), params.direction));
	return (true);
}
