/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 11:18:47 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_object	cube(void)
{
	return ((t_object){
		.intersect = cube_intersect,
		.normal_at = cube_normal_at,
		.inverse_matrix = matrix_identity(4),
		.material = color_normal()
	});
}
