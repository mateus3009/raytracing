/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:54:58 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 17:55:38 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_cylinder(t_rt_data *data, void	**args)
{
	t_object	*obj;
	t_point		origin;
	double		radius;
	t_pixel		color;
	t_cylinder	*props;
	t_list		*temp;

	if (!cylinder(obj))
		return (false);
	origin = *(t_point*)args[0];
	radius = *(double*)args[2] / 2.;
	color = *(t_pixel*)args[4];
	add_transformation(obj, translate(origin.x, origin.y, origin.z));
	add_transformation(obj, scaling(radius, 1, radius));
	add_transformation(obj,
		from_to_rotation(vector(0, 1, 0), *(t_vector*)args[1]));
	props = (t_cylinder*)obj->data;
	props->max = *(double*)args[2] / 2.;
	props->min = -*(double*)args[2] / 2.;
	temp = ft_lstnew(obj);
	if (!temp)
	{
		free(obj);
		return (false);
	}
	ft_lstadd_front(&data->objects, temp);
	return (true);
}
