/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:00:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 18:35:32 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_ambient(t_rt_data *data, void **argv)
{
	double	ratio;

	ratio = *(double*)argv[0];
	if (ratio < 0 || 1 < ratio)
		return (false);
	data->ambient.ratio = *(double*)argv[0];
	data->ambient.color = *(t_pixel*)argv[1];
	return (true);
}
