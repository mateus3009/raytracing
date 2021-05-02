/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 21:30:12 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/01 22:05:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

static t_camera_param	sample_args(
	t_point origin,
	t_vector direction,
	double vfov)
{
	t_camera_param	p;

	p.look_from = origin;
	p.look_at = sum(p.look_from, direction);
	p.vertical_field_of_view = vfov;
	p.up = vector(0, 1, 0);
	p.aperture = 0;
	p.focus_distance = length(minus(p.look_at, p.look_from));
	p.aspect_ratio = 16. / 9.; //usar resolution;
	return (p);
}

bool	parse_camera(t_rt_data *data, void	**argv)
{
	t_camera		*cam;
	t_list			*temp;

	cam = camera(sample_args(*(t_point*)argv[0],
		*(t_vector*)argv[1], *(double*)argv[2]));
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
