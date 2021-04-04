/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:04:42 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 20:24:43 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	determinant(t_matrix matrix)
{
	double	det;
	int		index;

	if (matrix.size == 2)
		return (
			matrix.values[0][0] * matrix.values[1][1]
			- matrix.values[0][1] * matrix.values[1][0]);
	det = 0;
	index = matrix.size;
	while (index--)
		det += matrix.values[0][index] * cofator(matrix, 0, index);
	return (det);
}
