/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/14 17:41:17 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "./../objects.h"

typedef struct s_sphere
{
	t_point	origin;
	double	radius;
}				t_sphere;

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

bool			sphere_intersect(
	t_object object,
	t_ray ray,
	t_hit_range range,
	t_intersection * hit);

#endif
