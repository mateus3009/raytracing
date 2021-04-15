/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:00:48 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/14 22:47:36 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "./../tuple/tuple.h"
# include "./../util_function/util_function.h"
# include "./../ray/ray.h"

typedef struct s_camera
{
	t_point		origin;
	t_point		coner;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	z;
	t_vector	x;
	t_vector	y;
	double		lens_radius;
}				t_camera;

typedef struct s_camera_param
{
	t_point		look_from;
	t_point		look_at;
	t_vector	up;
	double		vertical_field_of_view;
	double		aspect_ratio;
	double		aperture;
	double		focus_distance;
}				t_camera_param;

t_camera		camera(t_camera_param c);
t_ray			get_ray(t_camera camera, double x, double y);

#endif
