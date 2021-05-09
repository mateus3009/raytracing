/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_complete.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 21:30:12 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:50:47 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

static bool	camera_params(t_camera_param **d, void **argv)
{
	t_camera_param	*p;

	if (*(double *)argv[3] < 0 || 180 < *(double *)argv[3])
		return (false);
	p = ft_calloc(sizeof(t_camera_param), 1);
	if (!p)
		fatal("erro");
	p->look_from = *(t_point *)argv[0];
	p->look_at = *(t_vector *)argv[1];
	p->up = *(t_vector *)argv[2];
	p->vertical_field_of_view = *(double *)argv[3];
	p->aperture = *(double *)argv[4];
	p->focus_distance = length(minus(p->look_at, p->look_from));
	*d = p;
	return (true);
}

bool	parse_camera_complete(t_rt_data *data, void	**argv)
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
