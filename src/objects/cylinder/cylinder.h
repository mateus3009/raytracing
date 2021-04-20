/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 17:08:53 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "./../objects_structs.h"

typedef struct s_cylinder_param
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	x1;
	double	x2;
}				t_cylinder_param;

typedef struct s_cylinder
{
	double	min;
	double	max;
	bool	closed;
}				t_cylinder;

t_object		cylinder();
bool			cylinder_intersect_body(
	t_object object,
	t_ray ray,
	t_range range,
	double *t);
bool			cylinder_intersect_cap(
	t_object object,
	t_ray ray,
	t_range range,
	double *t);
bool			cylinder_intersect(
	t_object object,
	t_ray ray,
	t_range range,
	double *t);
t_vector	cylinder_normal_at(
	void *data,
	t_point object_point);

#endif
