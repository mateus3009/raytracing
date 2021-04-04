/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:04:42 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 20:09:22 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	minor(t_matrix matrix, int y, int x)
{
	return determinant(submatrix(matrix, y, x));
}
