/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:36:22 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 12:43:19 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_vector	refract(t_vector in, t_vector n, double ratio)
{
	double	cos_theta;
	t_vector	r_perp;
	t_vector	r_parallel;

	cos_theta = fmin(dot(scalar(in, -1), n), 1);
	r_perp = scalar(sum(scalar(n, cos_theta), in), ratio);
	r_parallel = scalar(n, -sqrt(fabs(1 - dot(r_perp, r_perp))));
	return (sum(r_perp, r_parallel));
}
