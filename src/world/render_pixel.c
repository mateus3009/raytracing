/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:12:18 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/10 01:41:02 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

static t_pixel	gamma_correction(t_pixel p, int samples)
{
	double	k;

	k = 1 / (double)samples;
	return (pixel(
			sqrt(p.r * k),
			sqrt(p.g * k),
			sqrt(p.b * k)));
}

t_pixel	render_pixel(t_job *job, int x, int y)
{
	t_pixel	color;
	int		index;

	color = get_color(job,
			x / (double)(job->canvas.width - 1),
			y / (double)(job->canvas.height - 1));
	index = job->samples;
	while (--index)
		color = sum(color, get_color(job,
					(x + ft_rand())
					/ (double)(job->canvas.width - 1),
					(y + ft_rand())
					/ (double)(job->canvas.height - 1)));
	return (divide(color, job->samples));
}
