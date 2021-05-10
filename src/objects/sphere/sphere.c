/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/10 00:52:06 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sphere.h"

bool	sphere(t_object **obj, t_sphere_build params)
{
	*obj = object(0);
	if (!*obj)
		return (false);
	(*obj)->intersect = sphere_intersect;
	(*obj)->normal_at = sphere_normal_at;
	(*obj)->material.color = params.color;
	add_transformation(*obj,
		translate(params.origin.x, params.origin.y, params.origin.z));
	add_transformation(*obj,
		scaling(params.radius, params.radius, params.radius));
	return (true);
}
