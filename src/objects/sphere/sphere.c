/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 11:19:00 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sphere.h"

t_object	sphere(void)
{
	return ((t_object){
		.data = NULL,
		.intersect = sphere_intersect,
		.normal_at = sphere_normal_at,
		.inverse_matrix = matrix_identity(4),
		.material = color_normal()
	});
}
