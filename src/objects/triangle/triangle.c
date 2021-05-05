/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 22:25:22 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./triangle.h"

bool	triangle(t_object **obj)
{
	t_triangle	*t;

	t = malloc(sizeof(t_triangle));
	if (!t)
		return (false);
	*obj = malloc(sizeof(t_object));
	if (!*obj)
	{
		free(t);
		return (false);
	}
	t->p1 = point(0, 1, 0);
	t->p2 = point(-1, 0, 0);
	t->p3 = point(1, 0, 0);
	t->e1 = minus(t->p2, t->p1);
	t->e2 = minus(t->p3, t->p1);
	t->normal = normalize(cross(t->e1, t->e2));
	**obj = (t_object){
		.data = t,
		.color = pixel(.5, .5, .5),
		.intersect = triangle_intersect,
		.normal_at = triangle_normal_at,
		.matrix = matrix_identity(4),
		.inverse_matrix = matrix_identity(4),
		.material = color_normal()};
	return (true);
}
