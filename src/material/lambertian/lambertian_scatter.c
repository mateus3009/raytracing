/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian_scatter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:17:01 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 02:10:11 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lambertian.h"
#include "./../../objects/objects.h"

bool	lambertian_scatter(t_scatter_params p)
{
	t_point			target;

	target = sum(p.record->point, random_in_hemispere(p.record->normal));
	if (near_zero(target))
		target = p.record->normal;
	*p.scattered = ray(p.record->point, minus(target, p.record->point));
	*p.attenuation = filter(p.record);
	return (true);
}
