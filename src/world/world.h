/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:39:41 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 17:55:58 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "./../ray/ray.h"
# include "./../objects/objects.h"
# include "./../canvas/canvas.h"
# include "./../camera/camera.h"
# include "./../light/light.h"
# include "./../parser/parser.h"

typedef struct s_job
{
	t_canvas			canvas;
	t_ambient_light		ambient;
	t_samples_pixel		samples;
	int					depth;
	t_camera			camera;
	t_list				*objects;
}				t_job;

void	clear_job(void	*j);
bool	hit(t_ray ray, t_list *objs, t_intersection *rec);
t_pixel	get_color(t_job job, double w, double h);
t_pixel	render_pixel(t_job job, int x, int y);
void	render_job(t_job job);
bool	rt_data_to_job(t_rt_data rt, t_list	**jobs);

#endif
