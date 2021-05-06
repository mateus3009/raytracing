/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:36:48 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/06 00:07:13 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phong.h"

static t_pixel	lighting_ambient(
	t_light light,
	t_intersection hit)
{
	t_phong	material;
	t_pixel	partial;

	material = *(t_phong*)hit.object.material.data;
	partial = product(material.color, light.color);
	return (scalar(partial, material.ambient));
}

static t_pixel	lighting_diffuse(
	t_light light,
	t_intersection hit)
{
	t_phong		material;
	t_pixel		partial;
	t_vector	light_direction;
	double		light_dot_normal;

	material = *(t_phong*)hit.object.material.data;
	partial = product(material.color, light.color);
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

	material = *(t_phong*)hit.object.material.data;
	light_direction = normalize(minus(light.origin, hit.point));
	reflect_dot_eye = dot(
			reflect(scalar(light_direction, -1), hit.normal),
			normalize(scalar(hit.ray.direction, -1)));
	if (reflect_dot_eye <= 0)
		return (pixel(0, 0, 0));
	return (scalar(light.color,
			material.specular * pow(reflect_dot_eye, material.shininess)));
}

t_pixel	lighting(
	t_light light,
	t_intersection hit)
{
	t_pixel	result;
	t_pixel	ambient;
	t_pixel	diffuse;
	t_pixel	specular;

	ambient = lighting_ambient(light, hit);
	diffuse = lighting_diffuse(light, hit);
	specular = pixel(0, 0, 0);
	if (!tuple_equal(diffuse, pixel(0, 0, 0)))
		specular = lighting_specular(light, hit);
	result = sum(sum(ambient, diffuse), specular);
	result.a = 0;
	return (specular);
}

bool	phong_scatter(
	t_material material,
	t_ray r_in,
	t_intersection rec,
	t_pixel *attenuation,
	t_ray *scattered)
{
	t_pixel	result;
	t_pixel	ambient;
	t_pixel	diffuse;
	t_pixel	specular;
	t_light	light;

	ambient = lighting_ambient(light, rec);
	diffuse = lighting_diffuse(light, rec);
	specular = pixel(0, 0, 0);
	if (!tuple_equal(diffuse, pixel(0, 0, 0)))
		specular = lighting_specular(light, rec);
	*attenuation = sum(sum(ambient, diffuse), specular);
	attenuation->a = 0;
	return (false);
}
