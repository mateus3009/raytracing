/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 17:20:41 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "objects_structs.h"
# include "./../transform/transform.h"
# include "./sphere/sphere.h"
# include "./plane/plane.h"
# include "./cube/cube.h"
# include "./cylinder/cylinder.h"
# include "./cone/cone.h"
# include "./square/square.h"
# include "./disk/disk.h"
# include "./triangle/triangle.h"

t_object		*object(size_t data_size);
bool			intersect(
					t_object obj,
					t_ray ray,
					t_range range,
					t_intersection *hit);
t_intersection	intersection(
					t_object object,
					t_ray world_ray,
					double t);
t_vector		normal_at(
					t_object object,
					t_point world_point);
void			add_transformation(
					t_object *object,
					t_matrix matrix);
void			free_object(void *data);

#endif
