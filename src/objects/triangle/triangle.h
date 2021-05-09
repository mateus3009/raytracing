/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:40:41 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "./../objects.h"

typedef struct s_triangle_params
{
	t_vector	d_e2;
	double		det;
	t_vector	pl_to_origin;
	double		f;
	double		u;
	t_vector	o_e1;
	double		v;
}				t_triangle_params;

typedef struct s_triangle
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_point		e1;
	t_point		e2;
	t_vector	normal;
}				t_triangle;

typedef struct s_triangle_build
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_pixel		color;
}				t_triangle_build;

bool			triangle(
					t_object **obj,
					t_triangle_build params);
bool			triangle_intersect(
					t_object object,
					t_ray ray,
					t_range range,
					double *t);
t_vector		triangle_normal_at(
					void *data,
					t_point object_point);

#endif
