/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:33:55 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 12:47:38 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dielectric.h"

t_material	dielectric(double refraction_ratio)
{
	t_dielectric	*dielectric;
	t_material		material;

	dielectric = malloc(sizeof(t_dielectric));
	if (!dielectric)
		exit(1);
	dielectric->refraction_ratio = refraction_ratio;
	material.data = dielectric;
	material.scatter = dielectric_scatter;
	return (material);
}
