/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:13:29 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 23:56:45 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_pixel	get_color(t_job job, double w, double h)
{
	t_intersection	record;
	t_pixel			color;

	color = pixel(0, 0, 0);
	if (hit(get_ray(job.camera, w, h), job.objects, &record))
		color = divide(sum(normalize(record.normal), vector(1, 1, 1)), 2);
	return (clamp_tuple(color, 0, .99));
}
