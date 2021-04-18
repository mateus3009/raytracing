/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/17 20:59:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./plane.h"

t_object	plane()
{
	return ((t_object){
		.intersect = plane_intersect,
		.inverse_matrix = matrix_identity(4),
		.material = material()
	});
}
