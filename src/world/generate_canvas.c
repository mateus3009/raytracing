/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_canvas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 19:47:08 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 21:21:55 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"


static void	clamp_screen_size(t_rt_data	rt, t_display display)
{
	if (rt.resolution.height > display.height)
		rt.resolution.height = display.height;
	if (rt.resolution.width > display.width)
		rt.resolution.width = display.width;
}

static void	*extract_canvas(void *data)
{
	t_job		*job;
	t_canvas	*c;

	if (!data)
		return (NULL);
	job = (t_job*)data;
	c = malloc(sizeof(t_canvas));
	c->height = job->canvas.height;
	c->width = job->canvas.width;
	c->pixels = job->canvas.pixels;
	return (c);
}

static void	render_all_jobs(t_list *job)
{
	if (job)
	{
		if (!render_job_with_threads(job->content))
			fatal("Failed to render the image");
		render_all_jobs(job->next);
	}
}

static void	free_job(void	*data)
{
	t_job	*job;

	job = (t_job*)data;
	free(job->camera);
	free(job);
}

t_list	*generate_canvas(char *filename, t_display *display)
{
	t_rt_data	rt;
	t_list		*jobs;
	t_list		*canvas;

	if (!process_file(filename, &rt))
		fatal("Failed to process the RT file");
	if (!rt_data_to_job(rt, &jobs) || !jobs)
		fatal("Failed to process the RT file");
	if (display)
		clamp_screen_size(rt, *display);
	ft_lstclear(&rt.cameras, free);
	render_all_jobs(jobs);
	canvas = ft_lstmap(jobs, extract_canvas, NULL);
	ft_lstclear(&(rt.objects), free_object);
	ft_lstclear(&(rt.light_points), free);
	ft_lstclear(&jobs, free_job);
	return (canvas);
}
