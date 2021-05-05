/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 00:34:49 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "./../objects.h"

typedef struct s_cone_param
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	x1;
	double	x2;
}				t_cone_param;

typedef struct s_cone
{
	double	min;
	double	max;
	bool	closed;
}				t_cone;

typedef struct s_cone_build
{
	t_point		origin;
	t_vector	direction;
	t_pixel		color;
	double		height_min;
	double		height_max;
	bool		is_closed;
}				t_cone_build;

bool			cone(t_object **obj, t_cone_build params);
bool			cone_intersect_body(
					t_object object,
					t_ray ray,
					t_range range,
					double *t);
bool			cone_intersect_cap(
					t_object object,
					t_ray ray,
					t_range range,
					double *t);
bool			cone_intersect(
					t_object object,
					t_ray ray,
					t_range range,
					double *t);
t_vector		cone_normal_at(
					void *data,
					t_point object_point);

#endif
