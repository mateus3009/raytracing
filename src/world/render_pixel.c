/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:12:18 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 22:40:05 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

static double	pixel_around_diff(t_canvas canvas, int x, int y, t_pixel color)
{
	double	max;
	double	current;

	max = 0;
	current = pixel_diff(color, get_pixel(canvas, x - 1, y + 1));
	if (current > max)
		max = current;
	current = pixel_diff(color, get_pixel(canvas, x - 1, y - 0));
	if (current > max)
		max = current;
	current = pixel_diff(color, get_pixel(canvas, x - 0, y + 1));
	if (current > max)
		max = current;
	return (max);
}

static t_pixel	gamma_correction(t_pixel p, int samples)
{
	double	k;

	k = 1 / (double)samples;
	return (pixel(
			sqrt(p.r * k),
			sqrt(p.g * k),
			sqrt(p.b * k)));
}

t_pixel	render_pixel(t_job job, int x, int y)
{
	t_pixel	color;
	double	diff;
	int		samples;
	int		index;

	color = get_color(job,
			x / (double)(job.canvas.width - 1),
			y / (double)(job.canvas.height - 1));
	diff = pixel_around_diff(job.canvas, x, y, color);
	samples = clamp(job.samples_per_pixel * diff,
			10, job.samples_per_pixel);
	index = samples;
	while (--index)
		color = sum(color, get_color(job,
					(x + ft_rand_range(-.7, .7))
					/ (double)(job.canvas.width - 1),
					(y + ft_rand_range(-.7, .7))
					/ (double)(job.canvas.height - 1)));
	return (gamma_correction(color, samples));
}
