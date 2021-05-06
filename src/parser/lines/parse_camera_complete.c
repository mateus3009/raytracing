/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_complete.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 21:30:12 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 18:58:09 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_camera_complete(t_rt_data *data, void	**argv)
{
	t_camera		*cam;
	t_list			*temp;

	t_camera_param	p;

	if (*(double*)argv[3] < 0 || 180 < *(double*)argv[3])
		return (false);
	p.look_from = *(t_point*)argv[0];
	p.look_at = *(t_point*)argv[1];
	p.up = *(t_vector*)argv[2];
	p.vertical_field_of_view = *(double*)argv[3];
	p.aperture = *(double*)argv[4];
	p.focus_distance = length(minus(p.look_at, p.look_from));
	p.aspect_ratio = data->resolution.width / data->resolution.height;

	cam = camera(p);
	if (!cam)
		return (false);
	temp = ft_lstnew(cam);
	if (!temp)
	{
		free(cam);
		return (false);
	}
	ft_lstadd_front(&data->cameras, temp);
	return (true);
}
