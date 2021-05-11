/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:54:19 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 02:03:51 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	clear_arg_parsers_results(int argc, void ***results)
{
	int	index;

	index = 0;
	while (index < argc)
		free((*results)[index++]);
	free(*results);
	*results = NULL;
}

bool	process_args(int argc,
	char **argv,
	t_rt_arg_parser *parsers,
	void ***results)
{
	int	index;

	if (!parsers || !*parsers)
		return (true);
	*results = malloc(sizeof(void *) * argc);
	if (!*results)
		return (false);
	index = 0;
	while (index < argc - 1)
	{
		if (!(parsers[index])(argv[index + 1], &(*results)[index]))
		{
			clear_arg_parsers_results(index, results);
			return (false);
		}
		index++;
	}
	return (true);
}
