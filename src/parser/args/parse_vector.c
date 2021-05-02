/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:22:29 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/01 20:46:36 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_args.h"
#include "./../../tuple/tuple.h"

bool	parse_vector(char *in, void **result)
{
	if (!parse_tuple(in, result))
		return (false);
	(**(t_vector**)result).w = 0;
	return (true);
}
