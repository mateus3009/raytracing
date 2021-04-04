/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:14:50 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 18:29:16 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static double	product_value(t_matrix a, t_matrix b, int x, int y)
{
	double	result;
	int		index;

	result = 0;
	index = a.size;
	while (index--)
		result += a.values[y][index] * b.values[index][x];
	return (result);
}

t_matrix		matrix_multiply(t_matrix a, t_matrix b)
{
	t_matrix	result;
	int			row;
	int			column;

	if (a.size != b.size)
		return (matrix(a.size));
	result = matrix(a.size);
	row = a.size;
	while (row--)
	{
		column = a.size;
		while (column--)
		{
			result.values[row][column] = product_value(a, b, column, row);
		}
	}
	return (result);
}
