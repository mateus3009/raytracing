/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:00:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:52:30 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_light(t_rt_data *data, void **args)
{
	t_light		*l;
	t_list		*temp;

	if (!light(&l,
			*(double *)args[1], *(t_pixel *)args[2], *(t_point *)args[0]))
		return (false);
	temp = ft_lstnew(l);
	if (!temp)
	{
		free(l);
		return (false);
	}
	ft_lstadd_front(&data->light_points, temp);
	return (true);
}
