/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:33:55 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 10:39:19 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lambertian.h"

t_material	lambertian(t_pixel albedo)
{
	t_lambertian	*lambertian;
	t_material		material;

	lambertian = malloc(sizeof(t_lambertian));
	if (!lambertian)
		exit(1);
	lambertian->albedo = albedo;
	material.data = lambertian;
	material.scatter = lambertian_scatter;
	return (material);
}
