/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 00:22:20 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "./../objects.h"

typedef struct s_plane_build
{
	t_point		origin;
	t_vector	direction;
	t_pixel		color;
}				t_plane_build;

bool		plane(t_object **obj, t_plane_build params);
bool		plane_intersect(
				t_object object,
				t_ray ray,
				t_range range,
				double *t);
t_vector	plane_normal_at(
				void *data,
				t_point object_point);

#endif
