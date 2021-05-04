/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 19:01:35 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

bool	square(t_object **obj)
{
	*obj = malloc(sizeof(t_object));
	if (!*obj)
		return (false);
	**obj = (t_object){
		.data = NULL,
		.color = pixel(.5, .5, .5),
		.intersect = square_intersect,
		.normal_at = square_normal_at,
		.matrix = matrix_identity(4),
		.inverse_matrix = matrix_identity(4),
		.material = color_normal()
	};
	return (true);
}
