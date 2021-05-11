/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_scatter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:36:48 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 02:12:47 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phong.h"
#include "./../../objects/objects.h"

static t_pixel	lighting_diffuse(
	t_light light,
	t_intersection hit)
{
	t_phong		material;
	t_pixel		partial;
	t_vector	light_direction;
	double		light_dot_normal;

	material = *(t_phong *)hit.object.material.data;
	partial = product(filter(&hit), light.color);
	light_direction = normalize(minus(light.origin, hit.point));
	light_dot_normal = dot(light_direction, hit.normal);
	if (light_dot_normal < 0)
		return (pixel(0, 0, 0));
	return (scalar(partial, material.diffuse * light_dot_normal));
}

static t_pixel	lighting_specular(
	t_light light,
	t_intersection hit)
{
	t_phong		material;
	t_vector	light_direction;
	double		reflect_dot_eye;

	material = *(t_phong *)hit.object.material.data;
	light_direction = normalize(minus(light.origin, hit.point));
	reflect_dot_eye = dot(
			reflect(scalar(light_direction, -1), hit.normal),
			normalize(scalar(hit.ray.direction, -1)));
	if (reflect_dot_eye <= 0)
		return (pixel(0, 0, 0));
	return (scalar(light.color,
			material.specular * pow(reflect_dot_eye, material.shininess)));
}

bool	is_shadowed(t_job *job, t_light l, t_intersection rec)
{
	t_vector	direction;
	double		distance;

	direction = minus(l.origin, rec.point);
	distance = length(direction);
	if (!hit(ray(rec.point, normalize(direction)), job->objects, &rec))
		return (false);
	return (rec.t < distance);
}

t_pixel	lighting(t_job *job, t_light l, t_intersection rec)
{
	t_pixel	result;
	t_pixel	diffuse;
	t_pixel	specular;

	specular = pixel(0, 0, 0);
	if (is_shadowed(job, l, rec))
		return (specular);
	diffuse = lighting_diffuse(l, rec);
	if (!tuple_equal(diffuse, specular))
		specular = lighting_specular(l, rec);
	result = sum(diffuse, specular);
	result.a = 0;
	return (result);
}

bool	phong_scatter(t_scatter_params p)
{
	int		index;
	t_pixel	color;
	t_list	*lights;

	index = 0;
	color = pixel(0, 0, 0);
	lights = (t_list *)p.job->light_points;
	while (lights)
	{
		color = sum(color,
				lighting(p.job, *(t_light *)(lights->content), *(p.record)));
		lights = lights->next;
		index++;
	}
	*p.attenuation = clamp_tuple(color, 0, 1);
	return (false);
}
