/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:04:42 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 20:14:41 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	cofator(t_matrix matrix, int y, int x)
{
	if ((y + x) % 2)
		return (minor(matrix, y, x) * -1);
	return (minor(matrix, y, x));
}
