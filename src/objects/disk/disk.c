/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:31:21 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 00:38:52 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"

bool	disk(t_object **obj, t_disk_build params)
{
	*obj = object(0);
	if (!*obj)
		return (false);
	(*obj)->intersect = disk_intersect;
	(*obj)->normal_at = disk_normal_at;
	(*obj)->color = params.color;
	add_transformation(*obj,
		scaling(params.radius, params.radius, params.radius));
	add_transformation(*obj,
		translate(params.origin.x, params.origin.y, params.origin.z));
	add_transformation(*obj,
		from_to_rotation(vector(0, 1, 0), params.direction));
	return (true);
}
