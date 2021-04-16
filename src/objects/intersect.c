/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 08:46:20 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/16 08:58:15 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

bool	intersect(
	t_object obj,
	t_ray ray,
	t_hit_range range,
	t_intersection *hit)
{
	return (obj.intersect(obj, ray, range, hit));
}
