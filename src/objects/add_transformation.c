/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_transformation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:19:07 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/02 11:49:28 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	add_transformation(t_object *object, t_matrix matrix)
{
	t_matrix	result;

	result = matrix_multiply(object->matrix, matrix);
	object->inverse_matrix = matrix_invert(result);
}
