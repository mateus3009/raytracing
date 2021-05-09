/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 21:30:12 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 22:12:02 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

static bool	camera_params(t_camera_param **d, void **argv)
{
	t_vector	temp;
	t_camera_param	*p;

	if (*(double*)argv[2] < 0 || 180 < *(double*)argv[2])
		return (false);
	p = ft_calloc(sizeof(t_camera_param), 1);
	p->look_from = *(t_point*)argv[0];
	p->look_at = sum(p->look_from, *(t_vector*)argv[1]);
	p->vertical_field_of_view = *(double*)argv[2];
	p->up = vector(0, 1, 0);
	p->focus_distance = length(minus(p->look_at, p->look_from));
	*d = p;
	return (true);
}

bool	parse_camera(t_rt_data *data, void	**argv)
{
	t_camera_param	*params;
	t_list			*temp;

	if (!camera_params(&params, argv))
		return (false);
	temp = ft_lstnew(params);
	if (!temp)
	{
		free(params);
		return (false);
	}
	ft_lstadd_front(&data->cameras, temp);
	return (true);
}
