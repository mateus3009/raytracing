/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:36:48 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/17 17:52:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "light.h"

static t_pixel	lighting_ambient(
	t_light light,
	t_intersection hit)
{
	t_material	material;
	t_pixel	partial;

	material = hit.object.material;
	partial = product(material.color, light.intensity);
	return (scalar(partial, material.ambient));
}

static t_pixel	lighting_diffuse(
	t_light light,
	t_intersection hit)
{
	t_material	material;
	t_pixel		partial;
	t_vector	light_direction;
	double		light_dot_normal;

	material = hit.object.material;
	partial = product(material.color, light.intensity);
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
	t_material	material;
	t_vector	light_direction;
	double		reflect_dot_eye;

	material = hit.object.material;
	light_direction = normalize(minus(light.origin, hit.point));
	reflect_dot_eye = dot(
		reflect(scalar(light_direction, -1), hit.normal),
		normalize(scalar(hit.ray.direction, -1)));
	if (reflect_dot_eye <= 0)
		return (pixel(0, 0, 0));
	return (scalar(light.intensity,
		material.specular * pow(reflect_dot_eye, material.shininess)));
}

t_pixel	lighting(
	t_light light,
	t_intersection hit)
{
	t_pixel result;
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
	return (result);
}
