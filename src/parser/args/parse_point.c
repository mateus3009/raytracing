/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:46:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/01 20:46:25 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_args.h"
#include "./../../tuple/tuple.h"

bool	parse_point(char *in, void **result)
{
	if (!parse_tuple(in, result))
		return (false);
	(**(t_point**)result).w = 1;
	return (true);
}
