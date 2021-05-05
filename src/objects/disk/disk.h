/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 00:25:21 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISK_H
# define DISK_H

# include "./../objects.h"

typedef struct s_disk_build
{
	t_point		origin;
	t_vector	direction;
	double		radius;
	t_pixel		color;
}				t_disk_build;

bool		disk(t_object **obj, t_disk_build params);
bool		disk_intersect(
				t_object object,
				t_ray ray,
				t_range range,
				double *t);
t_vector	disk_normal_at(
				void *data,
				t_point object_point);

#endif
