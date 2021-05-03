/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:55:39 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 16:51:46 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_rt_parser	*g_rt_parsers = (t_rt_parser[]){
	{.id = "c",
		.argc = 3,
		.line_parser = parse_camera,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_vector,
			parse_double}},
	NULL};

bool	find_parser(char *id, int argc, t_rt_parser *parser)
{
	t_rt_parser	*p;

	p = g_rt_parsers;
	while (p->arg_parsers)
	{
		if (!ft_strcmp(p->id, id) && p->argc == argc - 1)
		{
			*parser = *p;
			return (true);
		}
		p++;
	}
	return (false);
}
