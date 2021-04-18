/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:06:07 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 10:10:29 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vector	normal_at(t_object object, t_point world_point)
{
	t_point		object_point;
	t_vector	object_normal;
	t_vector	world_normal;

	object_point = matrix_product(object.inverse_matrix, world_point);
	object_normal = object.normal_at(object_point);
	world_normal = matrix_product(
		matrix_transpose(object.inverse_matrix),
		object_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}
