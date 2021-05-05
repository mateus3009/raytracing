/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:54:58 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 22:21:32 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_triangle(t_rt_data *data, void	**args)
{
	t_object	*obj;
	t_list		*temp;

	if (!triangle(&obj))
		return (false);
	temp = ft_lstnew(obj);
	if (!temp)
	{
		free(obj);
		return (false);
	}
	ft_lstadd_front(&data->objects, temp);
	return (true);
}
