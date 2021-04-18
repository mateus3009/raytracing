/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 10:23:40 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "./../objects_structs.h"

typedef struct s_sphere_params
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		det;
	double		x1;
	double		x2;
}				t_sphere_params;

t_object		sphere();
bool			sphere_intersect(
	t_object object,
	t_ray ray,
	t_range range,
	double *t);
t_vector	sphere_normal_at(
	t_point object_point);

#endif
