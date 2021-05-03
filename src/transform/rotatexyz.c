/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatexyz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:16:31 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 09:29:57 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_matrix	rotatexyz(double x, double y, double z)
{
	t_matrix	m;

	m = matrix_identity(4);
	m = matrix_multiply(m, rotatex(x));
	m = matrix_multiply(m, rotatey(y));
	m = matrix_multiply(m, rotatez(z));
	return (m);
}
