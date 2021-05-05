/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:45:02 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 17:30:58 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	*render_job(void *data)
{
	t_handle_job_data	jd;
	t_handle_job_params	jp;

	jd = *(t_handle_job_data*)data;
	jp.y = jd.job->canvas.height;
	while (--jp.y >= 0)
	{
		jp.start = (jd.job->canvas.width / jd.job->threads) * jd.thread_id;
		jp.end = (jd.job->canvas.width / jd.job->threads) * (jd.thread_id + 1);
		jp.x = jp.start - 1;
		while (++jp.x < jp.end)
			write_pixel(jd.job->canvas, jp.x, jp.y, render_pixel(jd.job, jp.x, jp.y));
	}
	return (NULL);
}
