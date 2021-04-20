/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 17:09:35 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "./../objects_structs.h"

t_object		cube();
bool			cube_intersect(
	t_object object,
	t_ray ray,
	t_range range,
	double *t);
t_vector	cube_normal_at(
	void *data,
	t_point object_point);

#endif
