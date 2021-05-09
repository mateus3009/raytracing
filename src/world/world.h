/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:39:41 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 16:03:41 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "./../util/util.h"
# include "./../ray/ray.h"
# include "./../objects/objects.h"
# include "./../canvas/canvas.h"
# include "./../camera/camera.h"
# include "./../light/light.h"
# include "./../parser/parser.h"
# include "./../display/display.h"

typedef struct s_job
{
	t_canvas			canvas;
	t_pixel				ambient;
	int					samples;
	int					depth;
	t_camera			*camera;
	t_list				*objects;
	t_list				*light_points;
	int					threads;
	t_pixel				bgc;
}				t_job;

typedef struct s_handle_job_data
{
	t_job	*job;
	int		thread_id;
}				t_handle_job_data;

typedef struct s_handle_job_params
{
	int		y;
	int		x;
	double	w;
	double	h;
	int		start;
	int		end;
}				t_handle_job_params;

void	clear_job(void	*j);
bool	hit(t_ray ray, t_list *objs, t_intersection *rec);
t_pixel	ray_color(t_job *job, t_ray r, int depth);
t_pixel	get_color(t_job *job, double w, double h);
t_pixel	render_pixel(t_job *job, int x, int y);
void	*render_job(void *data);
bool	rt_data_to_job(t_rt_data rt, t_list	**jobs);
bool	render_job_with_threads(t_job *job);
t_list	*generate_canvas(char *filename, t_display *display);

#endif
