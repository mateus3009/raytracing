/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:22:29 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/01 20:44:18 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_args.h"
#include "./../../tuple/tuple.h"

bool	parse_color(char *in, void **result)
{
	t_pixel	*t;

	if (!parse_tuple(in, result))
		return (false);
	t = *(t_pixel**)result;
	t->r /= 255;
	t->g /= 255;
	t->b /= 255;
	t->a = 0;
	if (t->r < 0 || 1 < t->r
		|| t->g < 0 || 1 < t->g
		|| t->b < 0 || 1 < t->b)
	{
		free(*result);
		return (false);
	}
	return (true);
}
