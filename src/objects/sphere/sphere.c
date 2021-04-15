/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/14 23:15:54 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sphere.h"

t_object	sphere()
{
	t_sphere	*s;

	s = malloc(sizeof(t_sphere));
	if (!s)
		exit(1);
	s->origin = point(0, 0, 0);
	s->radius = 1;
	return ((t_object){
		.data = s,
		.intersect = sphere_intersect
	});
}
