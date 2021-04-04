/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:14:50 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 16:48:28 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

bool	matrix_equal(t_matrix a, t_matrix b)
{
	char	row;
	char	column;

	if (a.size != b.size)
		return (false);
	row = a.size;
	while (row--)
	{
		column = a.size;
		while (column--)
		{
			if (a.values[row][column] != b.values[row][column])
				return (false);
		}
	}
	return (true);
}
