/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:45:02 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 22:41:15 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	render(t_job job)
{
	int				x;
	int				y;
	double			w;
	double			h;

	y = job.canvas.height;
	while (--y >= 0)
	{
		x = -1;
		while (x++ < job.canvas.width - 1)
			write_pixel(job.canvas, x, y, render_pixel(job, x, y));
	}
}
