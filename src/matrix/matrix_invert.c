/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:14:50 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 20:34:47 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	matrix_invert(t_matrix m)
{
	t_matrix	inverted;
	double		det;
	int			row;
	int			column;

	inverted = matrix(m.size);
	det = determinant(m);
	if (!det)
		return (inverted);
	row = m.size;
	while (row--)
	{
		column = m.size;
		while (column--)
			inverted.values[column][row] = cofator(m, row, column) / det;
	}
	return (inverted);
}
