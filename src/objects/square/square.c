/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 21:24:09 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

bool	square(t_object **obj, t_square_build params)
{
	*obj = object(0);
	if (!*obj)
		return (false);
	(*obj)->intersect = square_intersect;
	(*obj)->normal_at = square_normal_at;
	(*obj)->material.color = params.color;
	add_transformation(*obj,
		scaling(params.half_size, params.half_size, params.half_size));
	add_transformation(*obj,
		translate(params.origin.x, params.origin.y, params.origin.z));
	add_transformation(*obj,
		from_to_rotation(vector(0, 1, 0), params.direction));
	return (true);
}
