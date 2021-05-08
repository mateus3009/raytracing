/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:00:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/07 21:26:15 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_ambient(t_rt_data *data, void **argv)
{
	double	ratio;

	ratio = *(double*)argv[0];
	if (ratio < 0 || 1 < ratio)
		return (false);
	data->ambient = scalar(*(t_pixel*)argv[1], *(double*)argv[0]);
	return (true);
}
