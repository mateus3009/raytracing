/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:18:57 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/16 21:34:41 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

bool	hit(t_ray ray, t_list *lst, t_intersection *rec)
{
	bool			hit_something;
	t_range			range;
	t_intersection	temp;

	hit_something = false;
	range = (t_range){.min = .0001, .max = INFINITY};
	while (lst)
	{
		if (intersect(*(t_object*)lst->content, ray, range, &temp))
		{
			hit_something = true;
			range.max = temp.t;
			*rec = temp;
		}
		lst = lst->next;
	}
	return (hit_something);
}
