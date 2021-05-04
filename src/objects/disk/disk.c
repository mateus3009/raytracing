/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:31:21 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 19:31:22 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"

bool	disk(t_object **obj)
{
	*obj = malloc(sizeof(t_object));
	if (!*obj)
		return (false);
	**obj = (t_object){
		.data = NULL,
		.color = pixel(.5, .5, .5),
		.intersect = disk_intersect,
		.normal_at = disk_normal_at,
		.matrix = matrix_identity(4),
		.inverse_matrix = matrix_identity(4),
		.material = color_normal()
	};
	return (true);
}
