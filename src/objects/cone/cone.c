/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 20:04:47 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

bool	cone(t_object *obj)
{
	t_cone		*c;

	c = malloc(sizeof(t_cone));
	if (!c)
		return (false);
	c->min = -INFINITY;
	c->max = INFINITY;
	c->closed = false;
	obj = malloc(sizeof(t_object));
	if (!obj)
	{
		free(c);
		return (false);
	}
	*obj = (t_object){
		.data = c,
		.color = pixel(.5, .5, .5),
		.intersect = cone_intersect,
		.normal_at = cone_normal_at,
		.matrix = matrix_identity(4),
		.inverse_matrix = matrix_identity(4),
		.material = color_normal()};
	return (true);
}
