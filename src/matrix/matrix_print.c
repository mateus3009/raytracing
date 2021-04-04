/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:14:50 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 19:10:37 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	matrix_print(t_matrix m)
{
	int			row;
	int			column;

	printf("size: %d\n", m.size);
	row = 0;
	while (row < m.size)
	{
		column = 0;
		while (column < m.size)
		{
			printf("%.f\t", m.values[row][column]);
			column++;
		}
		printf("\n");
		row++;
	}
}
