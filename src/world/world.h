/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:39:41 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 11:23:36 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "./../ray/ray.h"
# include "./../objects/objects.h"
# include "./../canvas/canvas.h"
# include "./../camera/camera.h"
# include "./../light/light.h"

typedef struct s_job
{
	t_camera	camera;
	t_canvas	canvas;
	t_list		*objects;
	int			min_samples_per_pixel;
	int			max_samples_per_pixel;
	int			depth;
}				t_job;

bool	hit(t_ray ray, t_list *objs, t_intersection *rec);
t_pixel	get_color(t_job job, double w, double h);
t_pixel	render_pixel(t_job job, int x, int y);
void	render(t_job job);

#endif
