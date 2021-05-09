/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:16:16 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:41:15 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	free_object(void *data)
{
	t_object	*obj;

	obj = (t_object *)data;
	if (obj->data)
		free(obj->data);
	if (obj->material.data)
		free(obj->material.data);
	free(obj);
}
