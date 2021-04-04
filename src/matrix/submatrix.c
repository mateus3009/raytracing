/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:14:50 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 19:44:55 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	submatrix(t_matrix original, int y, int x)
{
	t_matrix	sub;
	int			row;
	int			column;
	int			row_;
	int			column_;

	sub = matrix(original.size - 1);
	row = 0;
	row_ = 0;
	while (row < original.size)
	{
		column = 0;
		column_ = 0;
		while (column < original.size)
		{
			sub.values[row_][column_] = original.values[row][column];
			if (column != x)
				column_++;
			column++;
		}
		if (row != y)
			row_++;
		row++;
	}
	return (sub);
}
