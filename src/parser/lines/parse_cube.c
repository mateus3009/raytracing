/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:54:58 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/02 12:12:29 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_cube(t_rt_data *data, void	**args)
{
	t_object	*obj;
	t_point		origin;
	double		size;
	t_pixel		color;

	if (!plane(obj))
		return (false);
	origin = *(t_point*)args[0];
	size = *(double*)args[1] / 2;
	color = *(t_pixel*)args[2];
	add_transformation(obj, translate(origin.x, origin.y, origin.z));
	add_transformation(obj, translate(size, size, size));
	return (true);
}
