/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:06:07 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 21:33:40 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	*object(size_t data_size)
{
	void		*data;
	t_object	*obj;

	data = NULL;
	if (data_size > 0)
	{
		data = malloc(data_size);
		if (!data)
			return (NULL);
	}
	obj = malloc(sizeof(t_object));
	if (!obj)
	{
		if (data_size > 0)
			free(data);
		return (NULL);
	}
	obj->data = data;
	obj->intersect = NULL;
	obj->normal_at = NULL;
	obj->material.color = pixel(.5, .5, .5);
	obj->material = lambertian();
	obj->matrix = matrix_identity(4);
	obj->inverse_matrix = obj->matrix;
	return (obj);
}
