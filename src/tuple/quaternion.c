/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:04:54 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 08:45:23 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	quaternion(double a, t_vector v)
{
	double	s_a;
	t_tuple	q;

	s_a = sin(a / 2.);
	q.x = v.x * s_a;
	q.y = v.y * s_a;
	q.z = v.z * s_a;
	q.w = cos(a / 2.);
	return (q);
}
