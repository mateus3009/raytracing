/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:00:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:53:11 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_resolution(t_rt_data *data, void **argv)
{
	int	width;
	int	height;

	width = *(int *)argv[0];
	height = *(int *)argv[1];
	if (width <= 0 || height <= 0)
		return (false);
	data->resolution.width = width;
	data->resolution.height = height;
	return (true);
}
