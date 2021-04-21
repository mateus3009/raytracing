/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:33:55 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 12:16:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "metal.h"

t_material	metal(t_pixel albedo, double fuzz)
{
	t_metal	*metal;
	t_material		material;

	metal = malloc(sizeof(t_metal));
	if (!metal)
		exit(1);
	metal->albedo = albedo;
	metal->fuzz = fuzz;
	material.data = metal;
	material.scatter = metal_scatter;
	return (material);
}
