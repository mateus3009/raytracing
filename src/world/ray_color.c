/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:13:29 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/07 21:36:52 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_pixel	ray_color(t_job *job, t_ray r, int depth)
{
	t_intersection	record;
	t_ray			scattered;
	t_pixel			attenuation;

	if (depth <= 0)
		return (pixel(0, 0, 0));
	if (hit(r, job->objects, &record))
	{
		if (record.object.material.scatter((t_scatter_params){.job = job,
			.material = record.object.material,
			.ray = r,
			.record = &record,
			.attenuation = &attenuation,
			.scattered = &scattered}))
			attenuation = product(attenuation, ray_color(job, scattered, depth - 1));
		return (sum(attenuation, job->ambient));
	}
	return (job->bgc);
}
