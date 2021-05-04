/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 19:30:48 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISK_H
# define DISK_H

# include "./../objects.h"

bool		disk(t_object **obj);
bool		disk_intersect(
				t_object object,
				t_ray ray,
				t_range range,
				double *t);
t_vector	disk_normal_at(
				void *data,
				t_point object_point);

#endif
