/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:13:29 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/06 00:08:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

static t_pixel	ray_color(t_job *job, t_ray r, t_list *objects, int depth)
{
	t_intersection	record;
	t_ray			scattered;
	t_pixel			attenuation;

	if (depth <= 0)
		return (pixel(0, 0, 0));
	if (hit(r, objects, &record))
	{
		if (record.object.material.scatter(record.object.material, r, record, &attenuation, &scattered))
			return (product(attenuation, ray_color(job, scattered, objects, depth - 1)));
		return (attenuation);
	}
	return (job->bgc);
}

t_pixel	get_color(t_job *job, double w, double h)
{
	t_pixel	color;

	color = ray_color(job,
		get_ray(job->camera, w, h),
		job->objects,
		job->depth);
	return (clamp_tuple(color, 0, .99));
}
