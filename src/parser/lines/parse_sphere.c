/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:54:58 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/02 11:51:47 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_sphere(t_rt_data *data, void	**args)
{
	t_object	*obj;
	t_point		origin;
	double		radius;
	t_pixel		color;

	if (!sphere(obj))
		return (false);
	origin = *(t_point*)args[0];
	radius = *(double*)args[1];
	color = *(t_pixel*)args[2];
	add_transformation(obj, translate(origin.x, origin.y, origin.z));
	add_transformation(obj, scaling(radius, radius, radius));
	return (true);
}
