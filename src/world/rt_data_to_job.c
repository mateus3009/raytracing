/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_to_job.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:54:22 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 16:07:29 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

static t_camera	*build_camera(t_rt_data rt, t_camera_param *p)
{
	t_camera	*cam;

	p->aspect_ratio = rt.resolution.width / rt.resolution.height;
	cam = camera(*p);
	if (!cam)
		fatal("Failed to create a camera");
	return (cam);
}

static bool	rt_data_to_single_job(t_rt_data rt, t_job **job)
{
	t_canvas	canvas;

	canvas = canvas_init(rt.resolution.width, rt.resolution.height);
	if (!canvas.pixels)
		return (false);
	*job = malloc(sizeof(t_job));
	if (!*job)
	{
		canvas_destroy(canvas);
		return (false);
	}
	**job = (t_job){
		.canvas = canvas,
		.ambient = rt.ambient,
		.samples = rt.samples,
		.depth = rt.depth,
		.camera = build_camera(rt, (t_camera_param*)rt.cameras->content),
		.objects = rt.objects,
		.light_points = rt.light_points,
		.threads = rt.threads,
		.bgc = rt.bgc};
	return (true);
}

bool	rt_data_to_job(t_rt_data rt, t_list	**jobs)
{
	t_job	*job;
	t_list	*container;

	*jobs = NULL;
	while (rt.cameras)
	{
		if (!rt_data_to_single_job(rt, &job))
		{
			ft_lstclear(jobs, clear_job);
			return (false);
		}
		container = ft_lstnew(job);
		if (!container)
		{
			ft_lstclear(jobs, clear_job);
			return (false);
		}
		ft_lstadd_front(jobs, container);
		rt.cameras = rt.cameras->next;
	}
	return (true);
}
