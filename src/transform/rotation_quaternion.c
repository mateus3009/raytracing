/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_quaternion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 09:13:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 09:13:48 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_matrix	rotation_quaternion(t_quaternion q)
{
	t_matrix	m;
	double		s;

	m = matrix_identity(4);
	s = pow(length(q), -2);
	m.values[0][0] = 1 - 2 * s * (q.y * q.y + q.z * q.z);
	m.values[0][1] = 2 * s * (q.x * q.y - q.z * q.w);
	m.values[0][2] = 2 * s * (q.x * q.z + q.y * q.w);

	m.values[1][0] = 2 * s * (q.x * q.y + q.z * q.w);
	m.values[1][1] = 1 - 2 * s * (q.x * q.x + q.z * q.z);
	m.values[1][2] = 2 * s * (q.y * q.z - q.x * q.w);

	m.values[2][0] = 2 * s * (q.x * q.z - q.y * q.w);
	m.values[2][1] = 2 * s * (q.y * q.z + q.x * q.w);
	m.values[2][2] = 1 - 2 * s * (q.x * q.x + q.y * q.y);
	return (m);
}
