/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 21:59:28 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

t_object	cone(void)
{
	t_cone	*c;

	c = malloc(sizeof(t_cone));
	if (!c)
		exit(1);
	c->min = -INFINITY;
	c->max = INFINITY;
	c->closed = false;
	return ((t_object){
		.data = c,
		.intersect = cone_intersect,
		.normal_at = cone_normal_at,
		.inverse_matrix = matrix_identity(4),
		.material = material()
	});
}
