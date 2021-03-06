/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:42:47 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 16:30:22 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phong.h"

t_material	phong(t_pixel color,
	double diffuse,
	double specular,
	double shininess)
{
	t_phong		*phong;
	t_material	material;

	phong = malloc(sizeof(t_phong));
	if (!phong)
		exit(1);
	phong->diffuse = diffuse;
	phong->specular = specular;
	phong->shininess = shininess;
	material.data = phong;
	material.color = color;
	material.scatter = phong_scatter;
	return (material);
}
