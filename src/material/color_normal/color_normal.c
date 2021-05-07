/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:33:55 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/06 20:57:20 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_normal.h"
#include "./../../objects/objects.h"

t_material	color_normal(void)
{
	t_material		material;

	material.data = NULL;
	material.color = pixel(1, 1, 1);
	material.scatter = color_normal_scatter;
	return (material);
}
