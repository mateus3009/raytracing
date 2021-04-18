/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:45:02 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 16:56:44 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	render(t_job job)
{
	int		x;
	int		y;
	double	w;
	double	h;
	t_intersection	record;
	int		samples;

	t_light l = light(pixel(1, 1, 1), point(-10, 10, -10));
	y = job.canvas.height;
	while (--y >= 0)
	{
		x = -1;
		while (x++ < job.canvas.width - 1)
			write_pixel(job.canvas, x, y, render_pixel(job, x, y));
	}
}
