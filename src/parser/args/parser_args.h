/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:06:51 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 16:40:41 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_ARGS_H
# define PARSER_ARGS_H

# include "./../parser.h"

bool	parse_int(char *in, void **result);
bool	parse_tuple(char *in, void **result);
bool	parse_color(char *in, void **result);
bool	parse_vector(char *in, void **result);
bool	parse_double(char *in, void **result);
bool	parse_point(char *in, void **result);

#endif
