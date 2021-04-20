/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/19 22:21:12 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./plane.h"

t_object	plane()
{
	return ((t_object){
		.data = NULL,
		.intersect = plane_intersect,
		.normal_at = plane_normal_at,
		.inverse_matrix = matrix_identity(4),
		.material = material()
	});
}
