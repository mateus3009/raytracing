/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_samples.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:00:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 20:42:49 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_samples(t_rt_data *data, void **argv)
{
	int	min;
	int	max;

	min = *(int*)argv[0];
	max = *(int*)argv[1];
	if (min < 1 || max < 1 || max < min)
		return (false);
	data->samples.min = min;
	data->samples.max = max;
	return (true);
}
