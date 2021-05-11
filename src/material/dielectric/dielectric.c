/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:33:55 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 17:28:32 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dielectric.h"

t_material	dielectric(t_pixel color, double refraction_ratio)
{
	t_dielectric	*dielectric;
	t_material		material;

	dielectric = malloc(sizeof(t_dielectric));
	if (!dielectric)
		exit(1);
	dielectric->refraction_ratio = refraction_ratio;
	material.data = dielectric;
	material.color = color;
	material.scatter = dielectric_scatter;
	return (material);
}
