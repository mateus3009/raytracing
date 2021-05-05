/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 23:58:25 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

bool	cylinder(t_object **obj)
{
	t_cylinder	*data;

	*obj = object(sizeof(t_cylinder));
	if (!*obj)
		return (false);
	(*obj)->intersect = cylinder_intersect;
	(*obj)->normal_at = cylinder_normal_at;
	data = ((t_cylinder*)(*obj)->data);
	data->min = -INFINITY;
	data->max = INFINITY;
	data->closed = false;
	return (true);
}
