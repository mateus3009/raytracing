/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:27:44 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 07:38:13 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./camera.h"

t_camera	*camera(t_camera_param c)
{
	t_camera	*camera;
	double		viewport_height;
	double		viewport_width;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	viewport_height = tan(degrees_to_radians(
				c.vertical_field_of_view) / 2.) * 2;
	viewport_width = c.aspect_ratio * viewport_height;
	camera->origin = c.look_from;
	camera->z = normalize(minus(camera->origin, c.look_at));
	camera->x = scalar(normalize(cross(c.up, camera->z)), -1);
	camera->y = scalar(cross(camera->z, camera->x), -1);
	camera->horizontal = scalar(camera->x, viewport_width * c.focus_distance);
	camera->vertical = scalar(camera->y, viewport_height * c.focus_distance);
	camera->coner = minus(camera->origin, divide(camera->horizontal, 2));
	camera->coner = minus(camera->coner, divide(camera->vertical, 2));
	camera->coner = minus(camera->coner, scalar(camera->z, c.focus_distance));
	camera->lens_radius = c.aperture / 2.;
	return (camera);
}
