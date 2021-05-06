/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:33:55 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/06 08:39:02 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lambertian.h"

t_material	lambertian(t_pixel color)
{
	t_material		material;

	material.data = NULL;
	material.color = color;
	material.scatter = lambertian_scatter;
	return (material);
}
