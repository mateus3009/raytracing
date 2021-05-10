/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:13:29 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 17:56:14 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_pixel	ray_color(
	t_job *job,
	t_ray r,
	int depth)
{
	t_scatter_params	params;
	t_intersection		record;
	t_pixel				attenuation;
	t_ray				scattered;
	t_pixel				ambient;

	if (depth <= 0)
		return (pixel(0, 0, 0));
	if (hit(r, job->objects, &record))
	{
		params = (t_scatter_params){.job = job,
			.material = record.object.material,
			.ray = r,
			.record = &record,
			.attenuation = &attenuation,
			.scattered = &scattered};
		if (record.object.material.scatter(params))
		{
			attenuation = product(attenuation,
					ray_color(job, scattered, depth - 1));
		}
		ambient = product(job->ambient, params.material.color);
		return (sum(attenuation, ambient));
	}
	return (job->bgc);
}
