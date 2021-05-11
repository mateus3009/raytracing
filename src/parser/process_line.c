/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:56:26 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 02:06:28 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	clear_arg_parsers_results(int argc, void ***results)
{
	int	index;

	if (results && *results)
	{
		index = 0;
		while (index < argc - 1)
			free((*results)[index++]);
		free(*results);
		*results = NULL;
	}
}

bool	process_line(t_rt_data *data, char *line)
{
	char		**argv;
	int			argc;
	t_rt_parser	parser;
	void		**arg_parsed;
	bool		status;

	line = ft_strtrim(line, " \n\t\r");
	if (!line)
		return (false);
	ft_strreplace_all('\t', ' ', ft_strreplace_all('\r', ' ', line));
	argv = ft_split(line, ' ');
	argc = ft_count_segment(line, ' ');
	arg_parsed = NULL;
	status = *line == '#' || *line == '\n';
	if (!argc || !find_parser(argv[0], argc, &parser)
		|| !process_args(argc, argv, parser.arg_parsers, &arg_parsed)
		|| !parser.line_parser(data, arg_parsed) || (status = true))
	{
		free(line);
		free_strtoken(&argv, argc);
		if (arg_parsed)
			clear_arg_parsers_results(argc, &arg_parsed);
		return (status || !argc);
	}
	return (status);
}
