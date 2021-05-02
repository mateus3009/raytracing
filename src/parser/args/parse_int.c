/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:22:29 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/01 20:48:39 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_args.h"

bool	parse_int(char *in, void **result)
{
	*result = malloc(sizeof(int));
	if (!*result)
		return (false);
	**(int**)result = ft_atoi(in);
	return (true);
}
