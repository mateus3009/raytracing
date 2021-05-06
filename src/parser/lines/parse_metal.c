/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_metal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:00:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/06 08:44:50 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_metal(t_rt_data *data, void **argv)
{
	t_object	*obj;

	obj = (t_object*)data->objects->content;
	if (!obj)
		return (false);
	if (obj->material.data)
		free(obj->material.data);
	obj->material = metal(*(t_pixel*)argv[0], *(double*)argv[1]);
	return (true);
}
