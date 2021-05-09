/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:47:43 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 17:46:42 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STRUCT_H
# define PARSER_STRUCT_H

# include "./../util/util.h"
# include "./../tuple/tuple.h"

typedef struct s_resolution
{
	unsigned int	width;
	unsigned int	height;
}				t_resolution;

typedef struct s_rt_data
{
	t_resolution	resolution;
	t_pixel			ambient;
	int				samples;
	int				depth;
	t_list			*cameras;
	int				cameras_count;
	t_list			*objects;
	t_list			*light_points;
	int				threads;
	t_pixel			bgc;
}				t_rt_data;

typedef bool	(*t_rt_arg_parser)(char *in, void **result);
typedef bool	(*t_rt_line_parser)(t_rt_data *data, void **args);

typedef struct s_rt_parser
{
	char				*id;
	int					argc;
	t_rt_arg_parser		*arg_parsers;
	t_rt_line_parser	line_parser;
}				t_rt_parser;

#endif
