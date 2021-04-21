/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian_scatter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:17:01 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 11:01:30 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lambertian.h"
#include "./../../objects/objects.h"

bool	lambertian_scatter(
	t_material material,
	t_ray r_in,
	t_intersection rec,
	t_pixel *attenuation,
	t_ray *scattered)
{
	t_lambertian	*m;
	t_point			target;

	m = material.data;
	target = sum(rec.point, random_in_hemispere(rec.normal));
	if (near_zero(target))
		target = rec.normal;
	*scattered = ray(rec.point, minus(target, rec.point));
	*attenuation = m->albedo;
	return (true);
}
