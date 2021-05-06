/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:33:55 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/06 08:40:39 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "metal.h"

t_material	metal(t_pixel color, double fuzz)
{
	t_metal		*metal;
	t_material	material;

	metal = malloc(sizeof(t_metal));
	if (!metal)
		exit(1);
	metal->fuzz = fuzz;
	material.data = metal;
	material.color = color;
	material.scatter = metal_scatter;
	return (material);
}
