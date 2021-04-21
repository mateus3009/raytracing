/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal_scatter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:17:01 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 11:52:59 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "metal.h"
#include "./../../objects/objects.h"

bool	metal_scatter(
	t_material material,
	t_ray r_in,
	t_intersection rec,
	t_pixel *attenuation,
	t_ray *scattered)
{
	*attenuation = divide(sum(normalize(rec.normal), vector(1, 1, 1)), 2);
	return (false);
}
