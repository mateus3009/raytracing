/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lambertian.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:00:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/10 17:00:18 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_lambertian(t_rt_data *data, void **argv)
{
	t_object	*obj;

	if (!data->objects)
		return (true);
	obj = (t_object *)data->objects->content;
	if (obj->material.data)
		free(obj->material.data);
	obj->material = lambertian(*(t_pixel *)argv[0]);
	return (true);
}
