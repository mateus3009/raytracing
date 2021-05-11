/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quaternion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:00:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/10 17:14:30 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_quaternion(t_rt_data *data, void **argv)
{
	t_object		*obj;
	t_quaternion	q;

	if (!data->objects)
		return (true);
	obj = (t_object *)data->objects->content;
	q = quaternion(*(double *)argv[0], *(t_vector *)argv[1]);
	add_transformation(obj, rotation_quaternion(q));
	return (true);
}
