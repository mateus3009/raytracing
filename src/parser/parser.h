/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:47:43 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/01 23:16:51 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "./parser_struct.h"
# include "./args/parser_args.h"
# include "./lines/parser_lines.h"

bool	find_parser(char *id, int argc, t_rt_parser *parser);
bool	process_args(int argc,
			char **argv,
			t_rt_arg_parser *parsers,
			void ***results);
bool	process_line(t_rt_data *data, char *line);
bool	process_file(char *filename, t_rt_data *data);

#endif
