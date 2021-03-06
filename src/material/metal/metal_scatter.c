/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal_scatter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:17:01 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 02:10:31 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "metal.h"
#include "./../../objects/objects.h"

bool	metal_scatter(t_scatter_params p)
{
	t_metal		metal;
	t_vector	reflected;

	metal = *(t_metal *)(p.record->object.material.data);
	reflected = reflect(normalize(p.record->ray.direction), p.record->normal);
	*p.scattered = ray(p.record->point,
			sum(reflected, scalar(random_in_unit_sphere(), metal.fuzz)));
	*p.attenuation = filter(p.record);
	return (dot(reflected, p.record->normal) > 0);
}
