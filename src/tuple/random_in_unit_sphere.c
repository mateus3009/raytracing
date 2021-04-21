/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_in_unit_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:36:37 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 23:55:09 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_vector	random_in_unit_sphere(void)
{
	t_vector	v;

	while (true)
	{
		v = random_tuple_range(-1, 1);
		if (length(v) >= 1)
			continue ;
		v.w = 0;
		return (v);
	}
}
