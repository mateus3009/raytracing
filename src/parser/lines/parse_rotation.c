/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:00:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/10 17:14:17 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_rotation(t_rt_data *data, void **argv)
{
	t_object	*obj;

	if (!data->objects)
		return (true);
	obj = (t_object *)data->objects->content;
	add_transformation(obj,
		rotatexyz(
			degrees_to_radians(*(double *)argv[0]),
			degrees_to_radians(*(double *)argv[1]),
			degrees_to_radians(*(double *)argv[2])));
	return (true);
}
