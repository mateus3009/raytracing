/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rainbow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:54:58 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 01:50:43 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"
#include "./../../filter/filter.h"

bool	parse_rainbow(t_rt_data *data, void	**args)
{
	t_object	*obj;

	if (!data->objects)
		return (true);
	obj = (t_object *)data->objects->content;
	obj->filter = filter_rainbow;
	return (true);
}
