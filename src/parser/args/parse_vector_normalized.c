/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector_normalized.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:22:29 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/01 20:38:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_args.h"
#include "./../../tuple/tuple.h"

bool	parse_vector_normalized(char *in, void **result)
{
	if (!parse_vector(in, result))
		return (false);
	if (length(**(t_vector**)result) > 1)
	{
		free(*result);
		return	(false);
	}
	return (true);
}
