/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 00:36:54 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "./../objects.h"

typedef struct s_cube_build
{
	t_point		origin;
	double		half_size;
	t_vector	direction;
	t_pixel		color;
}				t_cube_build;

bool		cube(t_object **obj, t_cube_build params);
bool		cube_intersect(
				t_object object,
				t_ray ray,
				t_range range,
				double *t);
t_vector	cube_normal_at(
				void *data,
				t_point object_point);

#endif
