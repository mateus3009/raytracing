/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 21:24:21 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

bool	cylinder(t_object **obj)
{
	t_cylinder	*c;

	c = malloc(sizeof(t_cylinder));
	if (!c)
		return (false);
	c->min = -INFINITY;
	c->max = INFINITY;
	c->closed = false;
	*obj = malloc(sizeof(t_object));
	if (!*obj)
		return (false);
	**obj = (t_object){
		.data = c,
		.color = pixel(.5, .5, .5),
		.intersect = cylinder_intersect,
		.normal_at = cylinder_normal_at,
		.matrix = matrix_identity(4),
		.inverse_matrix = matrix_identity(4),
		.material = color_normal()};
	return (true);
}
