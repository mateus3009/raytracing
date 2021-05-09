/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:54:58 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:53:24 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_cone(t_rt_data *data, void **args)
{
	t_object	*obj;
	t_list		*temp;

	if (!cone(&obj, (t_cone_build){
			.origin = *(t_point *)args[0],
			.direction = *(t_vector *)args[1],
			.height_min = *(double *)args[2],
			.height_max = *(double *)args[3],
			.color = *(t_pixel *)args[4]}))
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
