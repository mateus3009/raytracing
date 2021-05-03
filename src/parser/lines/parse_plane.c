/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:54:58 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/02 12:16:51 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_plane(t_rt_data *data, void	**args)
{
	t_object	*obj;
	t_point		origin;

	if (!plane(obj))
		return (false);
	origin = *(t_point*)args[0];
	add_transformation(obj, translate(origin.x, origin.y, origin.z));
	return (true);
}
