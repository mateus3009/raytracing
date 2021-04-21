/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:42:47 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 21:53:33 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	material(void)
{
	return ((t_material){
		.color = pixel(1, 1, 1),
		.ambient = .1,
		.diffuse = .9,
		.specular = .9,
		.shininess = 200.
	});
}
