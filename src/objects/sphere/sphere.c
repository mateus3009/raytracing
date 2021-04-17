/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/17 16:04:19 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sphere.h"

t_object	sphere()
{
	return ((t_object){
		.intersect = sphere_intersect,
		.inverse_matrix = matrix_identity(4)
	});
}
