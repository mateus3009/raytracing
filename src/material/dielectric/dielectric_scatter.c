/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric_scatter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:17:01 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/06 21:00:04 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dielectric.h"
#include "./../../objects/objects.h"

static double reflectance(double cos, double ratio)
{
	double	r;

	r = (1. - ratio) / (1. + ratio);
	r = r * r;
	return (r + ((1. - r) * pow(1. - cos, 5.)));
}

bool	dielectric_scatter(t_scatter_params p)
{
	t_dielectric	m;
	double		ratio;
	t_vector	ndirection;
	double		cos_theta;
	double		sin_theta;

	m = *(t_dielectric *)p.material.data;
	ratio = m.refraction_ratio;
	if (p.record->front_face)
		ratio = 1. / ratio;
	ndirection = normalize(p.ray.direction);
	cos_theta = fmin(dot(scalar(ndirection, -1), p.record->normal), 1.);
	sin_theta = sqrt(1. - cos_theta * cos_theta);
	if (ratio * sin_theta > 1. || reflectance(cos_theta, ratio) > ft_rand())
		*p.scattered = ray(p.record->point, reflect(normalize(p.ray.direction), p.record->normal));
	else
		*p.scattered = ray(p.record->point, refract(normalize(p.ray.direction), p.record->normal, ratio));
	*p.attenuation = pixel(1, 1, 1);
	return (true);
}
