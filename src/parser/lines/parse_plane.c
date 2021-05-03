/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:54:58 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 17:40:19 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_plane(t_rt_data *data, void	**args)
{
	t_object	*obj;
	t_point		origin;
	t_vector	direction;
	t_pixel		color;

	if (!plane(obj))
		return (false);
	origin = *(t_point*)args[0];
	direction = *(t_vector*)args[1];
	color = *(t_pixel*)args[2];
	add_transformation(obj, translate(origin.x, origin.y, origin.z));
	add_transformation(obj, from_to_rotation(vector(0, 1, 0), direction));
	return (true);
}
