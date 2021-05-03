/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_to_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:54:23 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 16:55:54 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_matrix	from_to_rotation(t_vector a, t_vector b)
{
	double			r;
	t_vector		perp;
	t_quaternion	q;

	r = vectors_angle(a, b);
	perp = cross(a, b);
	q = quaternion(r, perp);
	return (rotation_quaternion(q));
}
