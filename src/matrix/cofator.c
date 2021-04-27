/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:04:42 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/27 14:02:27 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	cofator(t_matrix matrix, int y, int x)
{
	if ((y + x) % 2)
		return (ft_minor(matrix, y, x) * -1);
	return (ft_minor(matrix, y, x));
}
