/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:27:44 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 21:47:50 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./camera.h"

t_camera	camera(t_camera_param c)
{
	t_camera	camera;
	double		viewport_height;
	double		viewport_width;

	viewport_height = 2.
		* tan(degrees_to_radians(c.vertical_field_of_view) / 2.);
	viewport_width = viewport_height * c.aspect_ratio;
	camera.origin = c.look_from;
	camera.z = normalize(minus(camera.origin, c.look_at));
	camera.x = normalize(cross(c.up, camera.z));
	camera.y = cross(camera.z, camera.x);
	camera.horizontal = scalar(camera.x, viewport_width * c.focus_distance);
	camera.vertical = scalar(camera.y, viewport_height * c.focus_distance);
	camera.coner = minus(camera.origin, divide(camera.horizontal, 2));
	camera.coner = minus(camera.coner, divide(camera.vertical, 2));
	camera.coner = minus(camera.coner, scalar(camera.z, c.focus_distance));
	camera.lens_radius = c.aperture / 2.;
	return (camera);
}
