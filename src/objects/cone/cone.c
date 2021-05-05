/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 23:57:48 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

bool	cone(t_object **obj)
{
	t_cone	*data;

	*obj = object(sizeof(t_cone));
	if (!*obj)
		return (false);
	(*obj)->intersect = cone_intersect;
	(*obj)->normal_at = cone_normal_at;
	data = ((t_cone*)(*obj)->data);
	data->min = -INFINITY;
	data->max = INFINITY;
	data->closed = false;
	return (true);
}
