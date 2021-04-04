/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:14:50 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 18:58:47 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	matrix_transpose(t_matrix original)
{
	t_matrix	transposed;
	int			row;
	int			column;

	transposed = matrix(original.size);
	row = original.size;
	while (row--)
	{
		column = original.size;
		while (column--)
			transposed.values[row][column] = original.values[column][row];
	}
	return (transposed);
}
