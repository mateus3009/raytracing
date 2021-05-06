/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:18:57 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 22:20:09 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

bool	hit(t_ray ray, t_list *objs, t_intersection *rec)
{
	bool			hit_something;
	t_range			range;
	t_intersection	temp;

	hit_something = false;
	range = (t_range){.min = .01, .max = INFINITY};
	while (objs)
	{
		if (intersect(*(t_object *)objs->content, ray, range, &temp))
		{
			hit_something = true;
			range.max = temp.t;
			*rec = temp;
		}
		objs = objs->next;
	}
	return (hit_something);
}
