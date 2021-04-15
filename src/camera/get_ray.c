/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:39:05 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/14 22:46:36 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_ray	get_ray(t_camera camera, double x, double y)
{
	t_vector	offset;
	t_vector	direction;

	offset = vector(0, 0, 0); // TODO offset para blur
	direction = sum(camera.coner, scalar(camera.horizontal, x));
	direction = sum(direction, scalar(camera.vertical, y));
	direction = minus(direction, sum(camera.origin, offset));
	return (ray(camera.origin, direction));
}
