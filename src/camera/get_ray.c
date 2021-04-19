/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:39:05 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/19 08:29:14 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_ray	get_ray(t_camera camera, double x, double y)
{
	t_vector	rand;
	t_vector	offset;
	t_vector	direction;

	rand = scalar(random_vector_in_unit_disk(), camera.lens_radius);
	offset = sum(scalar(camera.x, rand.x), scalar(camera.y, rand.y));
	direction = sum(camera.coner, scalar(camera.horizontal, x));
	direction = sum(direction, scalar(camera.vertical, y));
	direction = minus(direction, sum(camera.origin, offset));
	return (ray(sum(camera.origin, offset), direction));
}
