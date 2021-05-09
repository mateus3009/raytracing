/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:22:29 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:42:52 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_args.h"
#include "./../../tuple/tuple.h"

bool	parse_vector(char *in, void **result)
{
	t_vector	v;

	if (!parse_tuple(in, result))
		return (false);
	v = **(t_vector **)result;
	v.w = 0;
	if (fabs(v.x) > 1
		|| fabs(v.y) > 1
		|| fabs(v.z) > 1)
	{
		free(*result);
		return (false);
	}
	**(t_vector **)result = normalize(v);
	return (true);
}
