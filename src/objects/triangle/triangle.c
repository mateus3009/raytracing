/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 23:57:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./triangle.h"

bool	triangle(t_object **obj)
{
	t_triangle	*data;

	*obj = object(sizeof(t_triangle));
	if (!*obj)
		return (false);
	(*obj)->intersect = triangle_intersect;
	(*obj)->normal_at = triangle_normal_at;
	data = (t_triangle*)((*obj)->data);
	data->p1 = point(0, 1, 0);
	data->p2 = point(-1, 0, 0);
	data->p3 = point(1, 0, 0);
	data->e1 = minus(data->p2, data->p1);
	data->e2 = minus(data->p3, data->p1);
	data->normal = normalize(cross(data->e1, data->e2));
	return (true);
}
