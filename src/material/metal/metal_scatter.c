/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal_scatter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:17:01 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 21:08:42 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "metal.h"
#include "./../../objects/objects.h"

bool	metal_scatter(
	t_material material,
	t_ray in,
	t_intersection rec,
	t_pixel *attenuation,
	t_ray *scattered)
{
	t_metal		metal;
	t_vector	reflected;

	metal = *(t_metal*)material.data;
	reflected = reflect(normalize(in.direction), rec.normal);
	*scattered = ray(rec.point,
		sum(reflected, scalar(random_in_unit_sphere(), metal.fuzz)));
	*attenuation = material.color;
	return (dot(reflected, rec.normal) > 0);
}
