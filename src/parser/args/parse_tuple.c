/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tuple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:22:29 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/01 22:01:00 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_args.h"
#include "./../../tuple/tuple.h"

bool	parse_tuple(char *in, void **result)
{
	char	**argv;
	int		argc;

	argv = ft_split(in, ',');
	argc = count_strtoken(argv);
	if (argc != 3)
	{
		free_strtoken(&argv);
		return (false);
	}
	*result = malloc(sizeof(t_tuple));
	if (!*result)
		return (false);
	**(t_tuple**)result = tuple(ft_atof(argv[0]),
		ft_atof(argv[1]), ft_atof(argv[2]), 0);
	free_strtoken(&argv);
	return (true);
}
