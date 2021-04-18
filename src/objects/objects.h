/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/17 18:51:36 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "objects_structs.h"
# include "./sphere/sphere.h"
# include "./plane/plane.h"

bool	intersect(
	t_object obj,
	t_ray ray,
	t_range range,
	t_intersection *hit);

#endif
