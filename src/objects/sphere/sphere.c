/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/16 22:53:05 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sphere.h"

t_object	sphere(t_matrix matrix)
{
	return ((t_object){
		.intersect = sphere_intersect,
		.matrix = matrix,
		.inverse_matrix = matrix_invert(matrix)
	});
}
