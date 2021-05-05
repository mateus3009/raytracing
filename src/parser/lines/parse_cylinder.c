/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:54:58 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 06:26:52 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_cylinder(t_rt_data *data, void	**args)
{
	t_object	*obj;
	t_list		*temp;

	if (!cylinder(&obj, (t_cylinder_build){
		.origin = *(t_point*)args[0],
		.direction = *(t_vector*)args[1],
		.radius = *(double*)args[2] / 2.,
		.height_min = -*(double*)args[3] / 2.,
		.height_max = *(double*)args[3] / 2.,
		.color = *(t_pixel*)args[4]}))
		return (false);
	temp = ft_lstnew(obj);
	if (!temp)
	{
		free(obj);
		return (false);
	}
	ft_lstadd_front(&data->objects, temp);
	return (true);
}
