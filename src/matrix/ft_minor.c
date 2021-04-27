/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:04:42 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/27 14:02:27 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	ft_minor(t_matrix matrix, int y, int x)
{
	return (determinant(submatrix(matrix, y, x)));
}
